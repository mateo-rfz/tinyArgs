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

            //if parameter start with '-' tinyArgs recognize this is flag
            if (arg[0] == '-')
            {
                flags.push_back(arg);
                flagCounter ++;
            }

            /* 
            هf the argument is not a flag (does not start with '-'), 
            and runArg is empty, store this argument as runArg
            فhis ensures that only the first non-flag argument is saved, 
            even if the user provides another one at the end.
            */

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
        /*
        Search for the flag in the `flags` vector:
        - if the flag exists, return its corresponding value from `fav`
        - if the flag does not exist  return an empty string.
    ‍   */

        //add this help line to helpmsg variable for show on help method
        helpmsg += flag + "->" + help + "\n";

        for (int i = 0 ; i < flagCounter ; i++)
        {
            /*
            if the function returns "&&TRUE&&" or "&&FALSE&&",
            it means the flag exists in the input flags but does not have a parameter
            */
            if (flag == flags[i])
            {
                return fav[flag];
            }
        }
        return "";
    }




    std::string TinyArgs::getLongFlagValue(std::string flag , std::string help)
    {   
        /*
        Search for the flag in the `flags` vector:
        - if the flag exists, return its corresponding value from `fav`
        - if the flag does not exist  return an empty string.
    ‍   */

        //add this help line to helpmsg variable for show on help method
        helpmsg += flag + "->" + help + "\n";

        for (int i = 0 ; i < flagCounter ; i++)
        {
            /*
            if the function returns "&&TRUE&&" or "&&FALSE&&",
            it means the flag exists in the input flags but does not have a parameter
            */
            if (flag == flags[i])
            {
                return fav[flag];
            }
        }
        return "";
    }






    bool TinyArgs::getShortFlag(std::string flag , std::string help)
    {
        /*
        Search for the flag in the `flags` vector:
        - if the flag exists, return true
        - if the flag does not exist  return false
    ‍   */


        //add this help line to helpmsg variable for show on help method
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
        /*
        Search for the flag in the `flags` vector:
        - if the flag exists, return true
        - if the flag does not exist  return false
    ‍   */


        //add this help line to helpmsg variable for show on help method
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
        /*
        If the program using this library has defined flags (added help messages)
        but the user did not provide any flags, return the help message.
        */
       
        if (flagCounter < 1 && ! helpmsg.empty())
        {
            return helpmsg;
        }
        return "";
    }
}