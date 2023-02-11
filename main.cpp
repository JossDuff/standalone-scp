#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

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
    string filename = "node-input.txt";
    vector<node> node_vec = parseInput(filename);


    return 0;
}
