/***
* Include files.
*/
#include "AppCommands.h"




/***
* Echo demonstrates a command execution function.
* the command prints the parameters it receives.
*/
bool CommandEcho(std::vector<std::string> params)
{
   for (auto it = params.begin(); it < params.end(); it++) {
      printf(it->c_str());
   }

   return(true);
}

bool CommandExit(std::vector<std::string> params)
{
    printf("exited the program");
    exit(0);
    return true;
}
/*addition function*/
bool CommandAddition(std::vector<std::string> params)
{
    int  sum = 0;
    for (auto it = params.begin(); it < params.end(); it++)
        sum = sum + atoi(it->c_str());

   printf("%d\n", sum);
   return true;
}
/*subtractcion function */
bool CommandSubtraction(std::vector<std::string> params)
{
    std::vector<std::string> temp;
    int sum = atoi((params.end() - 1)->c_str());

    for (auto it = params.rbegin(); it < params.rend(); it++)
        temp.push_back(it->c_str());
        
    for (auto it = temp.begin() + 1; it < temp.end(); it++)
        sum = sum - atoi(it->c_str());

    printf("%d\n", sum);
    return true;
}

/*Multiplying function*/
bool CommandMultiplying(std::vector<std::string> params)
{
    int sum = 1;
    for (auto it = params.begin(); it < params.end(); it++)
        sum =sum*atoi(it->c_str());
   

    printf("%d\n", sum);
    return true;
}

/*dividing function*/
bool CommandDividing(std::vector<std::string> params)
{
    std::vector<std::string> temp;
    int sum = atoi((params.end() - 1)->c_str());

    for (auto it = params.rbegin(); it < params.rend(); it++)
        temp.push_back(it->c_str());

    for (auto it = temp.begin() + 1; it < temp.end(); it++)
    {
        //preventing dividing in 0
        if (atoi(it->c_str()) == 0)
        {
            printf("error: can't divide in 0\n");
            exit(0);
        }
        sum = sum / atoi(it->c_str());
    }
    printf("%d\n", sum);
    return true;
}



