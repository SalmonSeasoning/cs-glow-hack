# cs-glow-hack

You need the Hazedumper offsets, place in same folder under file name "csgo.hpp"

Run `g++ -shared main.cc antiflash.cc glow.cc -o main.dll -std=c++17 -Wall -Werror -Wpedantic -O2` to compile.

-shared (make a DLL)

-o (output)

-Wall, -Werror, -Wpedantic (enable warnings and such)

-O2 (default flag, just an optimization level)

-std=c++17 (use C++ 17 standard)
