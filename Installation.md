Installing and Setting up MSYS2 (MinGW UCRT64 Toolchain)
Download and install MSYS2 from https://www.msys2.org/
Open the terminal:
Start → MSYS2 UCRT64 (Important: use UCRT64, not the default shell)
Update MSYS2 packages (run twice):
pacman -Syu
# Close and reopen terminal
pacman -Syu

Install build tools and compiler:
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain

Install CMake and Git:
pacman -S mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-git

Install Poco C++ Libraries:
pacman -S mingw-w64-ucrt-x86_64-poco
Add UCRT64 to your PATH (if not already):

export PATH="/ucrt64/bin:$PATH"

In brief,
- Open terminal
       Start → MSYS2 UCRT64
-Update packages
       pacman -Syu (twice)
- Install compiler/toolchain
       pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
- Install Poco
       pacman -S mingw-w64-ucrt-x86_64-poco
- Install CMake
       pacman -S mingw-w64-ucrt-x86_64-cmake
- Install Git
       pacman -S mingw-w64-ucrt-x86_64-git
- Build using CMake
       cmake .. && cmake --build .
- Run the program
       ./dns_resolver or ./build/dns_resolver.exe

