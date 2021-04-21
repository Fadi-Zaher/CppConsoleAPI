#ifndef COMMAND_H
#define COMMAND_H



#include <string>
#include <vector>



#define  CMD_PROMPED		"\n>"
#define  CMD_ECHO			"echo"
#define  PARAMS_START   '('
#define  PARAMS_SEP		','
#define  PARAMS_END		')'





class Commands;
typedef bool (*CommandCb)(std::vector<std::string> params);
		


std::string CommandName(std::string command_line);
std::vector<std::string> CommandParams(std::string command_line);

Commands* CommandsInit();
bool CommandAdd(Commands* Commands_list, std::string name, CommandCb pCallback);
bool CommandExec(Commands* Commands_list, std::string command_line);
#endif // !COMMAND_H
