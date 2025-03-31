#include "include/tinyArgs.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    targs::TinyArgs args(argc, argv);

    std::cout << "Run Arg: " << args.getRunArgs() << std::endl;
    return 0;
}
