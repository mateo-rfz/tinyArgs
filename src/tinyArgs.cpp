#include "../include/tinyArgs.hpp"


namespace targs
{
    tinyArgs::tinyArgs(int argc , char ** argv) : argCounter(argc) , args(argv)
    {
        convertToString();
        convertToMap();
        splitFlags();
    };


    void tinyArgs::convertToString()
    {
        for(int i = 0 ; i < argCounter ; i++)
        {
            fArgs.push_back(args[i]);
        }
    }


    void tinyArgs::convertToMap()
    {
        for(int i = 1 ; i < argCounter - 1 ; i++)
        {
            fav[fArgs[i]] = fArgs[i + 1];
        }
    }



    void tinyArgs::splitFlags()
    {
        for (std::string & arg : fArgs)
        {
            if (!arg.empty() && arg[0] == '-')
            {
                flags.push_back(arg);
            }
        }
    }
    


    std::vector<std::string> tinyArgs::readFlags()
    {
        return flags;
    }


    std::map<std::string , std::string> tinyArgs::readArgs()
    {
        return fav;
    }
}