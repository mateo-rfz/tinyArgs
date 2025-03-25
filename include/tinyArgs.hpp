#ifndef TINY_ARGS
#define TINY_ARGS


#include <iostream>
#include <vector>
#include <map>


namespace targs
{
    class TinyArgs
    {
        private : 
        int argCounter;
        std::vector<std::string> args;

        std::vector<std::string> shortFlags;
        std::vector<std::string> longFlags;
        std::map<std::string , std::string> fav; // flag and value




        void argFormatter(char ** argv);

        void flagSpliter();

        void setFAV();

        public : 
        TinyArgs(int argc , char ** argv);

        std::string getShortFlag(std::string flag);

        std::string getLongFlag(std::string flag);
    };
}


#endif
