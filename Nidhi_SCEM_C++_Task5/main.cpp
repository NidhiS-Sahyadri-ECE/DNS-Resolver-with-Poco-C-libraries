#include "recursive_resolver.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    RecursiveResolver resolver;

    std::cout << "===== DNS Resolver using Poco C++ Libraries =====\n";
    std::cout << "Type a domain name to resolve (or type 'exit' to quit):\n\n";

    std::string domain;
    while (true) {
        std::cout << "Domain: ";
        std::getline(std::cin, domain);

        if (domain == "exit") {
            std::cout << "Exiting DNS Resolver.\n";
            break;
        }

        if (domain.empty()) {
            std::cout << "Please enter a valid domain name.\n";
            continue;
        }

        std::vector<std::string> results = resolver.resolve(domain);

        if (results.empty()) {
            std::cout << "No IP addresses found for: " << domain << "\n";
        } else {
            std::cout << "Resolved IPs for " << domain << ":\n";
            for (const auto& ip : results) {
                std::cout << "  → " << ip << "\n";
            }
        }

        std::cout << "\n";
    }

    return 0;
}
