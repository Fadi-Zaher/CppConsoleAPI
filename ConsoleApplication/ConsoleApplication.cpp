// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string.h>
#include <iostream>

#include "../Commands/CommandsApi.h"
#include "AppCommands.h"







// Main function.
int main()
{
   // Indicates whther to continue reading input.
   bool running = true;

   // Initialize the commands object.
   Commands* pCommands = CommandsInit();

   // Assign the echo command function to the command list.
   CommandAdd(pCommands, CMD_ECHO, CommandEcho);
   CommandAdd(pCommands, CMD_EXIT, CommandExit);
   CommandAdd(pCommands, CMD_ADD, CommandAddition);
   CommandAdd(pCommands, CMD_SUB, CommandSubtraction);
   CommandAdd(pCommands, CMD_MUL, CommandMultiplying);
   CommandAdd(pCommands, CMD_DIV, CommandDividing);
   
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

