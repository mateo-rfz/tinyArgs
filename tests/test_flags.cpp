#include "include/tinyArgs.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    targs::TinyArgs args(argc, argv);

    if (args.getShortFlag("-d", "Debug mode")) {
        std::cout << "Debug mode enabled" << std::endl;
    }

    std::string file = args.getLongFlagValue("--file", "Input file");
    if (!file.empty()) {
        std::cout << "File: " << file << std::endl;
    }

    return 0;
}
