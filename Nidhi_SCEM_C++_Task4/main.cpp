#include "recursive_resolver.h"
#include <iostream>
using namespace std;

int main() {
    RecursiveResolver resolver;
    string domain;

    cout << "Enter domain to resolve recursively: ";
    cin >> domain;

    auto ips = resolver.resolve(domain);
    if (!ips.empty()) {
        cout << "Resolved IPs:\n";
        for (const auto& ip : ips) {
            cout << " - " << ip << endl;
        }
    } else {
        cout << "Failed to resolve the domain." << endl;
    }

    return 0;
}
