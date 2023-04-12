#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <bits/stdc++.h>
#include "main.h"

#define USE_SPDLOG // ??

using namespace std;

// A quick way to split strings separated via spaces.
// TODO: currently unused.  was being used to get the node's trusted slice
xdr::xvector<string> vec_tokenizer(string s)
{
    xdr::xvector<string> v;
    stringstream ss(s);
    string word;
    //cout << "slice: ";
    while (ss >> word) {
        v.push_back(word);
        //cout << word + " ";
    }
    //cout << "\n";
    return v;
}

// reads input file of nodes and their slices into a node vec
static xdr::xvector<stellar::NodeID> parseInput(string filename, map<stellar::NodeID, string> *node_name_map) {

    // open file
    ifstream input_file;
    input_file.open(filename);

    string curr_name;
    stellar::NodeID curr_node;
    xdr::xvector<stellar::NodeID> node_vec;
    // TODO: currently not used
    string curr_slice_str;

    // run until End Of File is reached
    while(!input_file.eof()){

        // get name
        getline(input_file, curr_name);
        //cout << "name: " + curr_name + "\n";

        // get slice as string
        // TODO: currently not used
        getline(input_file, curr_slice_str);

        // build node using name string and slice xvector
        curr_node = stellar::PubKeyUtils::random(); // Generate random key for the node

        // Add new node to the xvector of nodes
        node_vec.push_back(curr_node);

        // Add new node to the map
        (*node_name_map)[curr_node] = curr_name;

        // get a blank line
        // doesn't matter which string buffer is used because it'll get overwritten
        getline(input_file, curr_name);
    }

    // close file
    input_file.close();

    return node_vec;
}

// stellar::SCPQuorumSetPtr initQSet(vector<stellar::NodeID> const& nodes)
// {
//     vector<stellar::SCPQuorumSet> innerSets;
//     auto qset = std::make_shared<stellar::SCPQuorumSet>((nodes.size())/2 + 1, nodes, innerSets);
//     stellar::normalizeQSet(*qset);
//     return qset;
// }

// Each node will have an instance of this class which contains the SCP state machine
// and also is an SCPDriver which mediates communication between Ivy and that SCP.
// class TestSCP : public SCPDriver {...}


void stellar::TestSCP::signEnvelope(SCPEnvelope& envelope)
{
    // Do nothing -- we don't bother with signatures in this model.
}

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

// TODO: fix this to work for the trusted slice we set in node-input.txt
stellar::SCPQuorumSetPtr initQSet(xdr::xvector<stellar::NodeID> const& nodes)
{
    xdr::xvector<stellar::SCPQuorumSet> innerSets;
    auto qset = make_shared<stellar::SCPQuorumSet>((nodes.size())/2 + 1, nodes, innerSets);
    normalizeQSet(*qset);
    return qset;
}

// Network constructor
stellar::Network::Network(const xdr::xvector<stellar::NodeID> node_vec)
    :mNodeIDs(node_vec),
    mQSet(initQSet(mNodeIDs)),
    mQSetHash(stellar::xdrSha256(*mQSet))
{}


int main() {

    // Map of NodeID to name of the node
    map<stellar::NodeID, string> node_name_map;

    // Map of NodeID to vec of node's slice
    // TODO: there's probably a stellar type for the quorum slice, might not need this
    //map<stellar::NodeID, xdr::xvector<stellar::NodeID>>

    // Parse input file
    string filename = "node-input.txt";
    const xdr::xvector<stellar::NodeID> node_vec = parseInput(filename, &node_name_map);

    // TODO: move to a helper function file
    cout << "Printing nodes\n";
    map<stellar::NodeID, string>::iterator it = node_name_map.begin();
    while (it != node_name_map.end()) {
        cout << it->second << "\n";
        ++it;
    }

    unique_ptr<stellar::Network> gNetwork = std::make_unique<stellar::Network>(node_vec);

    // Need a TestSCP instance for each node
    // might also need a single network object


    return 0;
}
