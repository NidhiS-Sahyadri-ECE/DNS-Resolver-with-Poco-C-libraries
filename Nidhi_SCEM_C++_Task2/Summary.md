Day 2 involved implementing the actual DNS resolution logic using the PocoNet library. 
I wrote a main.cpp program that used Poco::Net::DNS::hostByName() to resolve domain names like www.google.com. 
The program extracted and displayed the canonical name and all resolved IP addresses of the domain. 
This implementation marked the completion of a fully functional DNS resolver at a basic level. 
The project was compiled and run through the MSYS2 UCRT64 terminal using CMake and Make, producing accurate and real-time DNS outputs. 
By the end of Day 2, you had a solid DNS querying system in place, which will serve as the base for caching and recursive resolution features in the upcoming stages.
