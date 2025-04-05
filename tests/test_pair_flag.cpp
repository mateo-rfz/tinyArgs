#include "include/tinyArgs.hpp"
#include <iostream>


int main(int argc, char* argv[]) {
    targs::TinyArgs args(argc, argv);

    if (args.getPairFlag("--help" , "-h", "help switch")) {
        std::cout << args.help() << std::endl;
    }

    std::string file = args.getLongFlagValue("--file", "Input file");
    if (!file.empty()) {
        std::cout << "File: " << file << std::endl;
    }

    return 0;
}
