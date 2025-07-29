In Task 4 of the DNS Resolver project, the focus was on implementing recursive DNS resolution using the Poco C++ libraries. 
A new class called `RecursiveResolver` was created with a `resolve()` function that takes a domain name as input and attempts to resolve it to one or more IP addresses. 
The resolution was handled using `Poco::Net::DNS::hostByName()`, which internally manages the recursive querying process, simulating the traversal from root to top-level and authoritative DNS servers. 
Proper error handling was implemented using `try-catch` blocks to manage invalid or unreachable domains gracefully, ensuring the program does not crash on failure. 
The function also logs failures to the console for better debugging. 
The recursive resolver was thoroughly tested with a variety of domain names, including valid domains like `google.com` and `openai.com`, as well as invalid ones to confirm robust error handling. 
Overall, the task successfully integrated recursive resolution into the main program, providing accurate results for multi-level domains and laying the foundation for further enhancements like caching and advanced DNS record handling.
