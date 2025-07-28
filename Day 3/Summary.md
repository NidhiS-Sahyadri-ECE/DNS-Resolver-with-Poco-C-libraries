On Day 3, the focus was on optimizing the DNS resolver by adding local caching to avoid repeated DNS lookups for the same domain. 
This improves performance and reduces redundant network calls.
1. Created a Cache Module:
A Cache class (likely in Cache.cpp and Cache.h) was implemented using a std::map or std::unordered_map to store domain-to-IP mappings.
It supports storing resolved IPs and retrieving them efficiently.

2. Integrated Caching into Main Logic:
On entering a domain name, the resolver first checks if the domain is in the cache.
If cached, it displays the IP immediately as [CACHE].
If not, it resolves the domain using Poco::Net::DNS::hostByName(), stores the result in the cache, and displays it as [LIVE].

3. Handled Build & Execution:
Rebuilt the project using CMake and make in the MSYS2 UCRT64 terminal.
Verified caching functionality with multiple domain queries (e.g., google.com, facebook.com, etc.).
The program correctly distinguishes between cache hits and fresh lookups.

4. Basic Error Handling:
Ensured that failed domain lookups don't crash the program.
Invalid inputs and exceptions (like HostNotFoundException) are handled with user-friendly error messages.


By the end of Day 3, the DNS Resolver became smarter and faster with caching capabilities, laying the foundation for recursive querying in Day 4. 
The system now avoids unnecessary repeated lookups, improving both speed and efficiency.
