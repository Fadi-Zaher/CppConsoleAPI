#ifndef COMMAND_API_H
#define COMMAND_API_H




	// Include files.
	#include <string>
	#include <vector>
	#include "Commands.h"







	//	Cammand Parsing.
	std::string CommandName(std::string command_line);
	std::vector<std::string> CommandParams(std::string command_line);

	//	Command list API.
	Commands* CommandsInit();
	bool CommandAdd(Commands* Commands_list, std::string name, CommandCb pCallback);
	bool CommandExec(Commands* Commands_list, std::string command_line);

#endif COMMAND_API_H