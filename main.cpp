#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
//#include "scp/LocalNode.h"
//#include "include/SHA.h"
#define USE_SPDLOG // ??
// @DEV I had to change stellar-core/src/crypto/Hex.h line 8 from 
    // #include "xdr/Stellar-types.h" 
    // to
    // #include "protocol-curr/xdr/Stellar-types.h"
 #include <crypto/Hex.h>
// #include <crypto/SecretKey.h>
// #include <crypto/SHA.h>
// #include <scp/SCP.h>
// #include <scp/Slot.h>
// #include <invariant/ConservationOfLumens.h>
// #include <scp/QuorumSetUtils.h>
// #include <util/Logging.h>
// #include <util/XDROperators.h>
// #include <lib/json/json.h>

using namespace std;

struct node {
    string name;
    vector<string> slice;
};

// A quick way to split strings separated via spaces.
vector<string> vec_tokenizer(string s)
{
    vector<string> v;
    stringstream ss(s);
    string word;
    cout << "slice: ";
    while (ss >> word) {
        v.push_back(word);
        cout << word + " ";
    }
    cout << "\n";
    return v;
}

// PublicKey makePublicKey(int i) {

//     auto makePublicKey = [](int i) {
//         auto hash = sha256("NODE_SEED_" + std::to_string(i));
//         auto secretKey = SecretKey::fromSeed(hash);
//         return secretKey.getPublicKey();
//     };

//     hash = sha256("NODE_SEED_" + to_string(i));
// }

// reads input file of nodes and their slices into a node vec
vector<node> parseInput(string filename) {

    // todo: don't use auto
    //auto hash = stellar::sha256("NODE_SEED_" + std::to_string(4));
    // REFERENCE: LocalNode(NodeID const& nodeID, bool isValidator, SCPQuorumSet const& qSet, SCPDriver& driver);
    //NodeID nodeID = makePublicKey(4);
    bool isValidator = false;
    //SCPQuorumSet qSet =
    //SCPDriver driver =
    //LocalNode newNode(nodeID, isValidator, qSet, driver);

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
        cout << "name: " + curr_name + "\n";

        // get slice as string
        getline(input_file, curr_slice_str);

        // build node using name string and slice vector
        curr_node.name = curr_name;
        curr_node.slice = vec_tokenizer(curr_slice_str);

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


    return 0;
}
