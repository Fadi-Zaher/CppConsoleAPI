
#include <map>
#include "../Baselib/BaseLib.h"
#include "../Commands/Commands.h"








/***
* 	Class constructor/distructor implementation.
*/
Commands::Commands()
{
}
Commands::~Commands()
{
	commands_dic.clear();
}





/***
* 	Add new command name and callback to list of commands.
*/
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


/***
* 	Find command clallback function in the commands list according to command name.
*/
CommandCb* Commands::Find(std::string name)
{
	CommandCb* pCommandCb = nullptr;
	std::map<std::string, CommandCb>::iterator it = this->commands_dic.find(name);
	if (it != this->commands_dic.end()) {
		pCommandCb = &(*it).second;
	}
	return (pCommandCb);
}




/***
* Call for command execution providing a list of parameters as strings.
*/
bool Commands::Exec(std::string name, std::vector<std::string> params)
{
	bool result = false;

	CommandCb* pCommandCb = this->Find(name);
	if (nullptr != pCommandCb) {
		result = (*pCommandCb)(params);
	}
	return (result);
}








