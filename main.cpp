#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <bits/stdc++.h>
#include <tuple>
#include "main.h"
#include "parser.h"

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
// In reference code, constructor just takes an integer and creates 
// that many nodes as well as a single quorum set for those node.
// In our model, we have a dynamic amount of nodes and quorum sets
stellar::Network::Network(
    const xdr::xvector<stellar::NodeID> *node_vec, 
    const map<stellar::NodeID, stellar::SCPQuorumSetPtr> *node_to_quorum
)
    :mNodeIDs(*node_vec),
    mQSet(*node_to_quorum)
    // TODO: might need this hash later
    //mQSetHash(stellar::xdrSha256(*mQSet))
{}

// TestSCP constructor
stellar::TestSCP::TestSCP(NodeID const& nodeID, SCPQuorumSet const& qSetLocal)
    // third arg is if node is validator or not
    : mSCP(*this, nodeID, true, qSetLocal) {};


// TODO: implement
void stellar::TestSCP::signEnvelope(SCPEnvelope& envelope) {}
stellar::SCPQuorumSetPtr stellar::TestSCP::getQSet(Hash const& qSetHash) {}
void stellar::TestSCP::emitEnvelope(SCPEnvelope const& envelope) {}
stellar::Hash stellar::TestSCP::getHashOf(std::vector<xdr::opaque_vec<>> const& vals) const {} // Compiler wouldn't accept without "const" here
stellar::ValueWrapperPtr stellar::TestSCP::combineCandidates(uint64 slotIndex, ValueWrapperPtrSet const& candidates) {}
void stellar::TestSCP::setupTimer(uint64 slotIndex, int timerID, std::chrono::milliseconds timeout, std::function<void()> cb) {}
void stellar::TestSCP::stopTimer(uint64 slotIndex, int timerID) {}


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

    unique_ptr<stellar::Network> gNetwork = make_unique<stellar::Network>(&node_vec, &node_to_quorum);


    const stellar::NodeID test_node = gNetwork->mNodeIDs[0];
    const stellar::SCPQuorumSet test_quorum = *gNetwork->mQSet.at(test_node);//node_to_quorum.at(node_vec[0]);
    unique_ptr<stellar::TestSCP> TestSCP_node = make_unique<stellar::TestSCP>(test_node, test_quorum);


    return 0;
}
