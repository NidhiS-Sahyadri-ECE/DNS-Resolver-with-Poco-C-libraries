#include "recursive_resolver.h"
#include <Poco/Net/DNS.h>
#include <Poco/Exception.h>
#include <iostream>

using namespace Poco::Net;
using namespace std;

vector<string> RecursiveResolver::resolve(const string& domain) {
    vector<string> ipAddresses;

    try {
        // Try direct resolution
        HostEntry entry = DNS::hostByName(domain);
        for (auto addr : entry.addresses()) {
            ipAddresses.push_back(addr.toString());
        }
    } catch (Poco::Exception& ex) {
        cerr << "Direct resolution failed: " << ex.displayText() << endl;
    }

    return ipAddresses;
}
