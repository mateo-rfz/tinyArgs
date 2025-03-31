#include "include/tinyArgs.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    targs::TinyArgs args(argc, argv);

    std::string file = args.getLongFlagValue("--file", "Input file");
    if (!file.empty()) {
        std::cout << "File: " << file << std::endl;
    }

    if (!args.msgIfNotUseFlags().empty()) {
        std::cout << std::endl <<  args.msgIfNotUseFlags();
    }

    return 0;
}
