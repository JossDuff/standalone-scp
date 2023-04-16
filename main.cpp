#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <bits/stdc++.h>
#include <tuple>
#include "main.h"

#define USE_SPDLOG // ??

using namespace std;

/*
    GENERAL TODO:
        [] change pointers to smart/unique pointers where appropriate 
        [] move pasrsing functions into their own file.  This will require some makefile refactoring
        [] using namespace std here because I figured it would be better to be explicit about which types are from stellar
            this might not be very readable though, and also confusing since main.h uses namespace stellar.  Resolve this
            so main.cpp and main.h use the same namespace
        [] Currently doesn't support inner sets.  node-input parsing will have to be re-worked to support inner sets.
            Inner sets as whole networks might be the key to hierarchical consensus.
        [] (maybe not needed) Support a custom threshold value of node-input.txt.  Currently it is majority.
        [] Make parsing more robust.  Lotta issues.  play around with node-input until it breaks
*/

/*
*** For reference (from executable.cpp)
static SCPQuorumSetPtr
initQSet(xdr::xvector<NodeID> const& nodes)
{
    xdr::xvector<SCPQuorumSet> innerSets;
    auto qset = std::make_shared<SCPQuorumSet>((nodes.size())/2 + 1, nodes, innerSets);
    normalizeQSet(*qset);
    return qset;
}

*/

// From reference code executable.cpp, but it's being used differently
// in executable.cpp, this is called once to create a single quorum set for a network
// in our model, we want to support many quorum sets for a network, so we call this for each node
stellar::SCPQuorumSetPtr initQSet(xdr::xvector<stellar::NodeID> const& nodes) {
    // TODO: support inner sets
    xdr::xvector<stellar::SCPQuorumSet> innerSets;
    // TODO: confirm that the first parameter is the threshold of nodes that need to agree
    auto qset = std::make_shared<stellar::SCPQuorumSet>((nodes.size())/2 + 1, nodes, innerSets);
    normalizeQSet(*qset);
    return qset;
}

// reads input file of nodes and their slices into a node vec
// returns a tuple of node vector, node->quorum mapping, and node->name mapping
tuple<
    xdr::xvector<stellar::NodeID>,
    map<stellar::NodeID, stellar::SCPQuorumSetPtr>,
    map<stellar::NodeID, string>> 
parseInput(string filename) {

    // open file
    ifstream input_file;
    input_file.open(filename);

    // return value: vector of nodes
    xdr::xvector<stellar::NodeID> node_vec;
    // return value: node->quorum mapping
    map<stellar::NodeID, stellar::SCPQuorumSetPtr> node_to_quorum;
    // return value: node->name mapping
    map<stellar::NodeID, string> node_to_name;

    // mapping to hold the node to the names of the nodes in it's quorum slice
    map<stellar::NodeID, string> node_to_quorum_names;

    // mapping to associate the name of a node to it's node ID
    // Used when constructing quorum slice of a node
    map<string, stellar::NodeID> name_to_node;

    string node_name;
    string quorum_str;
    stellar::NodeID new_node;

    // run until End Of File is reached
    while(!input_file.eof()){

        // get name
        getline(input_file, node_name);
        // Generate new node by creating random key
        new_node = stellar::PubKeyUtils::random(); 

        // Add new node to the returned vector of nodes
        node_vec.push_back(new_node);

        // Add new node to the returned map node->name
        node_to_name[new_node] = node_name;

        // Add new node to the name->node map
        name_to_node[node_name] = new_node;

        // get quorum slice as string to be later converted to a qSet
        getline(input_file, quorum_str);
        node_to_quorum_names[new_node] = quorum_str;

        // get a blank line
        // doesn't matter which string buffer is used because it'll get overwritten
        getline(input_file, node_name);
    }

    // loop through node vector and construct qSet for each node
    // This has to be done after to make sure we discovered all the nodes in node-input.txt
    xdr::xvector<stellar::NodeID> quorum_nodes;
    string quorum_nodes_str;
    for (stellar::NodeID i : node_vec) {
        // TODO: handle case when node isn't in this map
        // String of node names
        quorum_nodes_str = node_to_quorum_names.at(i);
        // vector of nodeIDs

        xdr::xvector<stellar::NodeID> quorum_vec;
        // TODO: not sure if I need to add the node whos owns this slice to the vector, of if it is done in TestSCP initialization
        quorum_vec.push_back(i);
        stringstream ss(quorum_nodes_str);
        string node_name;
        stellar::NodeID curr_node;
        // turns node name strings (space separated) into a vector of NodeID
        while (ss >> node_name) {
            // gets the nodeID of the current node name
            // TODO: handle case when node_name doesn't yet exist in mapping
            curr_node = name_to_node[node_name];
            // Add the nodeID to the vector
            quorum_vec.push_back(curr_node);
        }

        // map of nodeID to Qset
        node_to_quorum[i] = initQSet(quorum_vec);
    }

    // close file
    input_file.close();

    // return tuple
    return make_tuple(node_vec, node_to_quorum, node_to_name);
}

// Each node will have an instance of this class which contains the SCP state machine
// and also is an SCPDriver which mediates communication between Ivy and that SCP.
// class TestSCP : public SCPDriver {...}
/*
void stellar::TestSCP::signEnvelope(SCPEnvelope& envelope)
{
    // Do nothing -- we don't bother with signatures in this model.
}
*/

/*
stellar::SCPQuorumSetPtr stellar::TestSCP::getQSet(Hash const& qSetHash)
{
    // We support exactly 1 qset in this model. (TODO: are we sure about this?)
    // TODO: How does it access gNetwork when it's uninitialized
    if (qSetHash != gNetwork->mQSetHash)
    {
        setLocalLogPrefix();
        cout<< "can't find qset hash {}" + hexAbbrev(qSetHash);
        throw std::runtime_error("can't find qset hash");
    }
    return gNetwork->mQSet;
}
*/

// Network constructor
stellar::Network::Network(
    const xdr::xvector<stellar::NodeID> *node_vec, 
    const map<stellar::NodeID, stellar::SCPQuorumSetPtr> *node_to_quorum
)
    :mNodeIDs(*node_vec),
    mQSet(*node_to_quorum)
    // TODO: might need this hash later
    //mQSetHash(stellar::xdrSha256(*mQSet))
{}


int main() {

    // node-input file to be parsed
    string filename = "node-input.txt";

    // parse input into a tuple
    tuple<
        xdr::xvector<stellar::NodeID>,
        map<stellar::NodeID, stellar::SCPQuorumSetPtr>,
        map<stellar::NodeID, string>> 
    result = parseInput(filename);

    // unwraps result tuple
    xdr::xvector<stellar::NodeID> node_vec = get<0>(result);
    map<stellar::NodeID, stellar::SCPQuorumSetPtr> node_to_quorum = get<1>(result);
    map<stellar::NodeID, string> node_to_name = get<2>(result);

    cout << "Printing nodes via node_to_name mapping\n";
    for(auto it = node_to_name.cbegin(); it != node_to_name.cend(); ++it) {
        cout << it->second << "\n";
    }

    cout << "\nPrinting nodes via node_vec\n";
    for(stellar::NodeID i: node_vec) {
        cout << node_to_name[i] << "\n";
    }

    cout << "\nPrinting quorum slices\n";
    stellar::SCPQuorumSetPtr curr_quorum;
    stellar::NodeID curr_node;
    for(auto it = node_to_quorum.cbegin(); it != node_to_quorum.cend(); ++it) {
        curr_node = it->first;
        curr_quorum = it->second;
        cout << "Quorum slice for node: " << node_to_name[curr_node] << "\n";
        for(stellar::NodeID i: curr_quorum->validators) {
            cout << "   " << node_to_name[i] << "\n";
        }
    }

    // TODO: change quorum map to also accept map of node to quorum
    unique_ptr<stellar::Network> gNetwork = std::make_unique<stellar::Network>(&node_vec, &node_to_quorum);

    // Need a TestSCP instance for each node
    // might also need a single network object


    return 0;
}
