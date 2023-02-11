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
vector<string> tokenizer(string s)
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

int main() {

    string filename = "node-input.txt";
    vector<node> node_vec;

    ifstream input_file;
    input_file.open(filename);


    string curr_name;
    string curr_slice_str;
    string buff;
    node curr_node;

    while(true){
        // get name
        getline(input_file, curr_name);
        cout << "name: " + curr_name + "\n";

        // get slice
        getline(input_file, curr_slice_str);

        curr_node.name = curr_name; 
        curr_node.slice = tokenizer(curr_slice_str);

        // get a blank line
        // doesn't matter which string buffer is used because it'll get overwritten
        getline(input_file, curr_name);

        node_vec.push_back(curr_node);
        break;
    }

    input_file.close();

    return 0;
}

//void parseInput()