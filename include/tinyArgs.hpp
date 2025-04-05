#ifndef TINY_ARGS_HPP
#define TINY_ARGS_HPP


#include <iostream>
#include <vector>
#include <map>


namespace targs
{
    class TinyArgs
    {
        private : 
        int argCounter;
        int flagCounter;

        std::vector<std::string> flags;

        //all the flags parameters save string on fav
        std::map<std::string , std::string> fav;
        std::string runArg = "";
        
        std::string helpmsg;



        public : 
        TinyArgs(int argc , char ** argv);

        std::string getShortFlagValue(std::string flag , std::string help);
        std::string getLongFlagValue(std::string flag , std::string help);
        std::string getPairFlagValue(std::string lFlag , std::string sFlag , std::string help);

        bool getShortFlag(std::string flag , std::string help);
        bool getLongFlag(std::string flag , std::string help);
        bool getPairFlag(std::string lFlag , std::string sFlag , std::string help);

        std::vector<std::string> getAllFlags();

        std::map<std::string , std::string>  getAllFlagsAndValue();

        std::string help();

        std::string msgIfNotUseFlags();

        std::string getRunArgs();
    };
}


#endif
