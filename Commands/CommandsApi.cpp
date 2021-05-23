
/***
* Include files.
*/
#include "../BaseLib/BaseLib.h"
#include "../Commands/CommandsApi.h"





/***
* Command special characters.
*/
#define  PARAMS_START   '('
#define  PARAMS_SEP		','
#define  PARAMS_END		')'





/***
* Parsing the command name from the command string.
*/
std::string CommandName(std::string command_line)
{
	int cnd_end = command_line.find(PARAMS_START);
	std::string command = command_line.substr(0, cnd_end);
	return(trim(command));
}


/**
* Parsing the command parameters from the command string
*/
std::vector<std::string> CommandParams(std::string command_line)
{
	std::vector<std::string> params;
	std::vector<std::string>::iterator it = params.end();

	int prm_strt = command_line.find(PARAMS_START) + sizeof(PARAMS_START);
	int prm_end = command_line.find(PARAMS_END);
	std::string params_str = command_line.substr(prm_strt, prm_end - prm_strt);


	do {
		std::string param = params_str;
		int prm_end = params_str.find(PARAMS_SEP);
		if (prm_end > 0) {
			param = params_str.substr(0, prm_end);
			params_str = params_str.substr(prm_end + sizeof(PARAMS_SEP), params_str.length());
		}
		else {
			params_str = "";
		}

		param = trim(param);
		it = params.insert(it, param);
	} while (!params_str.empty());

	return(params);
}





/***
* Creating a new commands list.
*/
Commands* CommandsInit()
{
	return new Commands();
}


/***
* Add new command name and function to the commands list.
*/
bool CommandAdd(Commands* Commands_list, std::string name, CommandCb pCallback)
{
	return (Commands_list->Add(name, pCallback));
}


/***
* Call for command execution providing a parameters list.
*/
bool CommandExec(Commands* Commands_list, std::string command_line)
{
	std::string name = CommandName(command_line);
	std::vector<std::string> params = CommandParams(command_line);
	return(Commands_list->Exec(name, params));
}
