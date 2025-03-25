
#include "../include/tinyArgs.hpp"


namespace targs
{
        TinyArgs::TinyArgs(int argc , char ** argv)
        {
            if (argc > 1)
            {
            argCounter = argc;
            argFormatter(argv);
            flagSpliter();
            setFAV();
            }
            else 
            {
                argCounter = -1;
            }
        }
        

        void TinyArgs::argFormatter(char ** argv)
        {
            for (int i = 1 ; i < argCounter ; i++)
            {
                args.push_back(argv[i]);
            }
        }

        void TinyArgs::flagSpliter()
        {
            for(int i = 0 ; i < args.size() ; i++)
            {
                std::string ar = args[i];
                if (i % 2 == 0)
                {
                    if (ar.size() > 2 && ar[0] == '-' && ar[1] == '-')
                    {
                        iLongFlags.push_back(ar);
                    }
                    else if (ar.size() > 1 && ar[0] == '-')
                    {
                        iShortFlags.push_back(ar);
                    }
                }
                
            }
        }




        void TinyArgs::setFAV()
        {
            if (args.size() % 2 == 1)
            {
                return;
            }

            for(int i = 0 ; i < args.size() - 1 ; i = i + 2)
            {
                fav[args[i]] = args[i + 1];
            }
        }






        std::string TinyArgs::getShortFlag(std::string flag , std::string help)
        {
            setedShortFlags.push_back(flag);
            setedShortFlags.push_back(help);

            if (argCounter == -1){return "";}

            for (int i = 0 ; i < iShortFlags.size() ; i++)
            {
                if (iShortFlags[i] == flag)
                {
                    return fav[flag];
                }
            }
            
            return "";
        }




        std::string TinyArgs::getLongFlag(std::string flag , std::string help)
        {
            setedLongFlags.push_back(flag);
            setedLongFlags.push_back(help);

            if (argCounter == -1){return "";}

            for (int i = 0 ; i < iLongFlags.size() ; i++)
            {
                if (iLongFlags[i] == flag)
                {
                    return fav[flag];
                }
            }

            return "";
        }






        std::string TinyArgs::msgIfNotUseFlag()
        {
            if (argCounter != -1){return "";}
        
            std::string msg;
        
            if (!setedShortFlags.empty()) {
                for (int i = 0; i < setedShortFlags.size() - 1; i = i + 2)
                {
                    msg += setedShortFlags[i] + " -> " + setedShortFlags[i + 1] + "\n";
                }
            }
        
            if (!setedLongFlags.empty()) {
                for (int i = 0; i < setedLongFlags.size() - 1; i = i + 2)
                {
                    msg += setedLongFlags[i] + " -> " + setedLongFlags[i + 1] + "\n";
                }
            }
        
            return msg;
        }
        

}
