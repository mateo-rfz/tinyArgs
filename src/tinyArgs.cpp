#include "../include/tinyArgs.hpp"


namespace targs
{
    TinyArgs::TinyArgs(int argc , char ** argv)
    {
        argCounter = argc;
        flagCounter = 0;


        //---------------------for standard args

        for(int i = 1 ; i < argCounter ; i++)
        {
            char * arg = argv[i];

            if (arg[0] == '-')
            {
                flags.push_back(arg);
                flagCounter ++;
            }
            else if(runArg.empty())
            {
                runArg = arg;
            }
                
            //(argv[i + 1])[0] -> the next arg
            if(i + 1 < argCounter && (argv[i + 1])[0] != '-')
            {
                fav[arg] = argv[i + 1];
                i = i + 1;
            }
            else
            {
                fav[arg] = "&&TRUE&&";
            }
        }
        
    }






    std::string TinyArgs::getShortFlagValue(std::string flag , std::string help)
    {   
        helpmsg += flag + "->" + help + "\n";

        for (int i = 0 ; i < flagCounter ; i++)
        {
            if (flag == flags[i])
            {
                return fav[flag];
            }
        }
        return "";
    }




    std::string TinyArgs::getLongFlagValue(std::string flag , std::string help)
    {   
        helpmsg += flag + "->" + help + "\n";

        for (int i = 0 ; i < flagCounter ; i++)
        {
            if (flag == flags[i])
            {
                return fav[flag];
            }
        }
        return "";
    }






    bool TinyArgs::getShortFlag(std::string flag , std::string help)
    {
        helpmsg += flag + "->" + help + "\n";

        for (int i = 0 ; i < flagCounter ; i++)
        {
            if (flag == flags[i])
            {
                return true;
            }
        }
        return false;
    }







    bool TinyArgs::getLongFlag(std::string flag , std::string help)
    {
        helpmsg += flag + "->" + help + "\n";

        for (int i = 0 ; i < flagCounter ; i++)
        {
            if (flag == flags[i])
            {
                return true;
            }
        }
        return false;
    }





    std::vector<std::string> TinyArgs::getAllFlags()
    {
        return flags;
    }





    std::map<std::string , std::string> TinyArgs::getAllFlagsAndValue()
    {
        return fav;
    }




    std::string TinyArgs::getRunArgs()
    {
        return runArg;
    }




    std::string TinyArgs::help()
    {
        return helpmsg;
    }



    std::string TinyArgs::msgIfNotUseFlags()
    {
        return helpmsg;
    }
}