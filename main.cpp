#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
//#include "scp/LocalNode.h"
//#include "include/SHA.h"
#define USE_SPDLOG // ??
// @DEV I had to change stellar-core/src/crypto/Hex.h line 8 from 
    // #include "xdr/Stellar-types.h" 
    // to
    // #include "protocol-curr/xdr/Stellar-types.h"
    // UPDATE: I fixed this in the makefile.  THIS CHANGE ISN'T NEEDED ANYMORE
// #include <crypto/Hex.h>
 #include <crypto/SecretKey.h>
// #include <crypto/SHA.h>
// #include <scp/SCP.h>
// #include <scp/Slot.h>
// #include <invariant/ConservationOfLumens.h>
// #include <scp/QuorumSetUtils.h>
// #include <util/Logging.h>
// #include <util/XDROperators.h>
// #include <lib/json/json.h>

using namespace std;

// TODO: I was working with a stuct like this for the initial attempt to keep
// track of node names and names of the nodes in their slice.  This is going
// to be un-maintainable as we work with more stellar-core types and functions.
// Best way to keep track of the names and slices will be a mapping of the 
// node's key (NodeID) to a name and to a vector of NodeID's of the nodes in 
// its slice
struct node {
    // name of the node from node-input.txt
    string name;
    // string of the names of trusted nodes from node-input.txt
    // TODO: might want to change this to a Qset or some other type from stellar-core
    vector<string> slice;
    // node public key
    stellar::NodeID keyID;
};

// A quick way to split strings separated via spaces.
vector<string> vec_tokenizer(string s)
{
    vector<string> v;
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
vector<node> parseInput(string filename) {

    // open file
    ifstream input_file;
    input_file.open(filename);

    string curr_name;
    string curr_slice_str;
    string buff;
    node curr_node;
    vector<node> node_vec;

    // run until End Of File is reached
    while(!input_file.eof()){

        // get name
        getline(input_file, curr_name);
        //cout << "name: " + curr_name + "\n";

        // get slice as string
        getline(input_file, curr_slice_str);

        // build node using name string and slice vector
        curr_node.name = curr_name;
        curr_node.slice = vec_tokenizer(curr_slice_str);
        curr_node.keyID = stellar::PubKeyUtils::random(); // Generate random key

        // Add new node to the vector of nodes
        node_vec.push_back(curr_node);

        // get a blank line
        // doesn't matter which string buffer is used because it'll get overwritten
        getline(input_file, curr_name);
    }

    // close file
    input_file.close();

    return node_vec;
}

int main() {
    // Parse input file
    string filename = "node-input.txt";
    vector<node> node_vec = parseInput(filename);

    // TODO: move to a helper function file
    cout << "PRINTING NODES AND TRUSTED SLICES (from node-input.txt) \n \n";
    for (int i = 0; i < node_vec.size(); i++) {
        node curr_node = node_vec[i];
        cout << "Node:           " << curr_node.name << "\n";
        cout << "Trusted slice:  ";
        for (int j = 0; j < curr_node.slice.size(); j++) {
            cout << curr_node.slice[j] << " ";
        }
        cout << "\n\n";
    }


    return 0;
}
