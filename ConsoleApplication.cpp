// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string.h>
#include <iostream>

#include "Command.h"







bool CommandEcho(std::vector<std::string> params)
{
   for (auto it = params.begin(); it<params.end(); it++) {
      printf(it->c_str());
   }

   return(true);
}



int main()
{
   bool running = true;
   Commands* pCommands = CommandsInit();
   CommandAdd(pCommands, CMD_ECHO, CommandEcho);
   
   std::string command_line;
   while (running)
   {
      std::cout << CMD_PROMPED;
      getline(std::cin, command_line);

      running = CommandExec(pCommands, command_line);
   }

   return(EXIT_SUCCESS);
}

