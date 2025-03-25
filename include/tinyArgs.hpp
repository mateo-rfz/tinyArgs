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
        std::vector<std::string> args;

        std::vector<std::string> iShortFlags; // input short flags
        std::vector<std::string> iLongFlags;
        std::map<std::string , std::string> fav; // flag and value

        std::vector<std::string> setedShortFlags;
        std::vector<std::string> setedLongFlags;





        void argFormatter(char ** argv);

        void flagSpliter();

        void setFAV();

        public : 
        TinyArgs(int argc , char ** argv);

        std::vector<std::string> getAllData();

        std::string getShortFlag(std::string flag , std::string help);

        std::string getLongFlag(std::string flag , std::string help);

        std::string msgIfNotUseFlag();

        std::string TinyArgs::help();
    };
}


#endif
