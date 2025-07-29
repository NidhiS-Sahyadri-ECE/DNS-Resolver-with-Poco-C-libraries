#include <iostream>
#include <Poco/Net/DNS.h>
#include <Poco/Net/HostEntry.h>
#include <Poco/Exception.h>
#include "Cache.h"  

using namespace Poco::Net;
using namespace Poco;
using namespace std;

int main() {
    Cache dnsCache; 
    string domain;

    while (true) {
        cout << "\nEnter domain (or 'exit'): ";
        cin >> domain;
        if (domain == "exit") break;

        try {
            string cachedIP = dnsCache.get(domain);
            if (!cachedIP.empty()) {
                cout << "[CACHE] IP for " << domain << ": " << cachedIP << endl;
            } else {
                HostEntry entry = DNS::hostByName(domain);
                auto addresses = entry.addresses();

                if (!addresses.empty()) {
                    string resolvedIP = addresses[0].toString();
                    dnsCache.set(domain, resolvedIP);
                    cout << "[LIVE] IP for " << domain << ": " << resolvedIP << endl;
                } else {
                    cout << "No IP addresses found." << endl;
                }
            }
        } catch (const Poco::Exception& ex) {
            cerr << "DNS lookup failed: " << ex.displayText() << endl;
        }
    }

    return 0;
}
