#include <Poco/Net/DNS.h>
#include <Poco/Net/HostEntry.h>
#include <iostream>

int main() {
        cout << "\nEnter domain (or 'exit'): ";
        cin >> domain;
    try {
        Poco::Net::HostEntry entry = Poco::Net::DNS::hostByName(domain);
        std::cout << "DNS Query Successful!" << std::endl;
    } catch (const Poco::Exception& ex) {
        std::cerr << "DNS Query Failed: " << ex.displayText() << std::endl;
    }

    return 0;
}
