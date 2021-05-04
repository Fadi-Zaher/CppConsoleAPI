// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string.h>
#include <iostream>

#include "Command.h"






//Echo demonstrates a command execution function.
// the command prints the parameters it receives.
bool CommandEcho(std::vector<std::string> params)
{
   for (auto it = params.begin(); it<params.end(); it++) {
      printf(it->c_str());
   }

   return(true);
}


// Main function.
int main()
{
   // Indicates whther to continue reading input.
   bool running = true;

   // Initialize the commands object.
   Commands* pCommands = CommandsInit();

   // Assign the command function to the command text.
   CommandAdd(pCommands, CMD_ECHO, CommandEcho);
   
   // Store user input text.
   std::string command_line;

   // Continues loop.
   while (running)
   {
      // Print command promped '>'
      std::cout << CMD_PROMPED;

      // Get console command text"
      getline(std::cin, command_line);
 
      // Call for command execution.
      running = CommandExec(pCommands, command_line);
   }

   return(EXIT_SUCCESS);
}

