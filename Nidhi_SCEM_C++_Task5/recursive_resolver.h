#ifndef RECURSIVE_RESOLVER_H
#define RECURSIVE_RESOLVER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>

class RecursiveResolver {
public:
    RecursiveResolver();
    std::vector<std::string> resolve(const std::string& domain);

private:
    std::unordered_map<std::string, std::vector<std::string>> cache;
    std::mutex cacheMutex;

    bool isCached(const std::string& domain);
    std::vector<std::string> getFromCache(const std::string& domain);
    void storeInCache(const std::string& domain, const std::vector<std::string>& ipAddresses);
};

#endif // RECURSIVE_RESOLVER_H
