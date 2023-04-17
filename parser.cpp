#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <bits/stdc++.h>
#include <tuple>

// Stellar includes
#include <crypto/Hex.h>
#include <crypto/SecretKey.h>
#include <crypto/SHA.h>
#include <scp/SCP.h>
#include <scp/Slot.h>
#include <scp/QuorumSetUtils.h>
#include <util/Logging.h>
#include <util/XDROperators.h>
#include <lib/json/json.h>

using namespace std;

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
