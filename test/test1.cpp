#include <iostream>
#include "include/tinyArgs.hpp"






int main(int argc , char ** argv)
{
    std::cout << "Hello welcome to Tiny arg parser" << std::endl;

    targs::TinyArgs a(argc , argv);


    std::string d =  a.getLongFlag("--time" , "only for time");
    if(d.size() > 0)
        std::cout << d << std::endl ;


    std::string b =  a.getShortFlag("-t" , "short flag for time");
    if(b.size() > 0)
        std::cout << b << std::endl ;



    std::string g =  a.getShortFlag("-a" , "use -a for hidden files");
    if(g.size() > 0)
        std::cout << g << std::endl ;

    return 0;

}