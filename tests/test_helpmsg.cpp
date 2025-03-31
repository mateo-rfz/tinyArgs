#include "include/tinyArgs.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    targs::TinyArgs args(argc, argv);

    if (args.getShortFlag("-h", "Display help message")) {
        std::cout << args.help();
    }

    return 0;
}
