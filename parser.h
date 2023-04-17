#include <map>

using namespace std;

stellar::SCPQuorumSetPtr initQSet(xdr::xvector<stellar::NodeID> const& nodes);

tuple<
    xdr::xvector<stellar::NodeID>,
    map<stellar::NodeID, stellar::SCPQuorumSetPtr>,
    map<stellar::NodeID, string>> 
parseInput(string filename);