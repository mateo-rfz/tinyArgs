#ifndef TINY_ARGP
#define TINY_ARGP

#include <string>
#include <vector>
#include <map>


namespace targs
{
    class tinyArgs
    {
        protected : 
            int argCounter ;
            char ** args ;

            std::vector<std::string> fArgs;
            std::vector<std::string> flags;
            std::map<std::string , std::string> fav; // flag and values 


            void convertToString();
            void convertToMap();
            void splitFlags();

        public : 
            tinyArgs(int argc , char ** argv);
            
            std::vector<std::string> readFlags();
            std::map<std::string , std::string> readArgs();
    };
}



#endif 