#include "recursive_resolver.h"
#include <Poco/Net/DNS.h>
#include <Poco/Net/HostEntry.h>
#include <Poco/Exception.h>
#include <iostream>

using namespace Poco::Net;
using namespace std;

RecursiveResolver::RecursiveResolver() {}

bool RecursiveResolver::isCached(const string& domain) {
    lock_guard<mutex> lock(cacheMutex);
    return cache.find(domain) != cache.end();
}

vector<string> RecursiveResolver::getFromCache(const string& domain) {
    lock_guard<mutex> lock(cacheMutex);
    return cache[domain];
}

void RecursiveResolver::storeInCache(const string& domain, const vector<string>& ipAddresses) {
    lock_guard<mutex> lock(cacheMutex);
    cache[domain] = ipAddresses;
}

vector<string> RecursiveResolver::resolve(const string& domain) {
    if (isCached(domain)) {
        cout << "[CACHE] Domain found: " << domain << endl;
        return getFromCache(domain);
    }

    vector<string> ipAddresses;
    try {
        HostEntry entry = DNS::hostByName(domain);
        HostEntry::AddressList addresses = entry.addresses();

        for (const auto& addr : addresses) {
            ipAddresses.push_back(addr.toString());
        }

        if (!ipAddresses.empty()) {
            storeInCache(domain, ipAddresses);
            cout << "[SUCCESS] Resolved domain: " << domain << endl;
        } else {
            cout << "[WARNING] No IPs found for: " << domain << endl;
        }
    } catch (Poco::Exception& ex) {
        cerr << "[ERROR] DNS resolution failed for " << domain << ": " << ex.displayText() << endl;
    }

    return ipAddresses;
}
