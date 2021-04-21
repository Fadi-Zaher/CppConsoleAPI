
#include <map>
#include "BaseLib.h"
#include "Command.h"





class Commands
{
	std::map<std::string, CommandCb> commands_dic;

	public:	Commands();
	public:	~Commands();

	public:	CommandCb*	Find(std::string name);
	public:	bool			Add(std::string name, CommandCb& pCallback);
	public:	bool			Exec(std::string name, std::vector<std::string> params);
};





Commands::Commands()
{
}

Commands::~Commands()
{
	commands_dic.clear();
}



CommandCb* Commands::Find(std::string name)
{
	CommandCb* pCommandCb = nullptr;
	std::map<std::string, CommandCb>::iterator it = this->commands_dic.find(name);
	if (it != this->commands_dic.end()) {
		pCommandCb = &(*it).second;
	}
	return (pCommandCb);
}

bool Commands::Add(std::string name, CommandCb& pCallback)
{
	bool result = true;
	if(nullptr == this->Find(name)) {
		this->commands_dic.insert(std::pair<std::string, CommandCb&>(name, pCallback));
	}
	else {
		result = false;
	}
	return(result);
}

bool Commands::Exec(std::string name, std::vector<std::string> params)
{
	bool result = false;

	CommandCb* pCommandCb = this->Find(name);
	if (nullptr != pCommandCb) {
		result = (*pCommandCb)(params);
	}

	return (result);
}










Commands* CommandsInit()
{
	return new Commands();
}

bool CommandAdd(Commands* Commands_list, std::string name, CommandCb pCallback)
{
	return (Commands_list->Add(name, pCallback));
}

std::string CommandName(std::string command_line)
{
	int cnd_end = command_line.find(PARAMS_START);
	int prms_end = command_line.find(PARAMS_END);

	std::string command = command_line.substr(0, cnd_end);	
	return(trim(command));
}


std::vector<std::string> CommandParams(std::string command_line)
{
	std::vector<std::string> params;
	std::vector<std::string>::iterator it = params.end();

	int prm_strt = command_line.find(PARAMS_START) + sizeof(PARAMS_START);
	int prm_end = command_line.find(PARAMS_END);
	std::string params_str = command_line.substr(prm_strt, prm_end - prm_strt);
	

	do{
		std::string param = params_str;
		int prm_end = params_str.find(PARAMS_SEP);
		if (prm_end > 0) {
			param = params_str.substr(0, prm_end);
			params_str = params_str.substr(prm_end+sizeof(PARAMS_SEP), params_str.length());
		}
		else {
			params_str = "";
		}

		param = trim(param);
		it = params.insert(it, param);
	}while(!params_str.empty());

	return(params);
}


bool CommandExec(Commands* Commands_list, std::string command_line)
{
	std::string name = CommandName(command_line);
	std::vector<std::string> params = CommandParams(command_line);
	return(Commands_list->Exec(name, params));
}