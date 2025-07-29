cmake_minimum_required(VERSION 3.10)

project(DNSResolver)

set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(src)

# Add executable with all source files
add_executable(dns_resolver
    src/main.cpp
    src/recursive_resolver.cpp
)

# Link Poco libraries
find_package(Poco REQUIRED Net Foundation Util)

target_link_libraries(dns_resolver Poco::Net Poco::Foundation Poco::Util)
