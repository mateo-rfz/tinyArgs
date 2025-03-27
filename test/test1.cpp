#include <iostream>
#include "include/tinyArgs.hpp"



using namespace targs;


int main(int argc , char ** argv)
{
    std::cout << "Hello welcome to Tiny arg parser" << std::endl;


    TinyArgs a(argc , argv);


    std::string bb = a.getShortFlagValue("-t" , "hey this is help");
    std::cout << bb;


    bool help = a.getShortFlag("-h" , "use for help");
    if (help)
    {
        std::cout << a.help() << std::endl;
    }    



    return 0;

}