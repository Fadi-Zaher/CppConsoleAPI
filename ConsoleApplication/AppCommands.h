#ifndef APP_COMMANDS_H
#define APP_COMMANDS_H




	// Include files.
	#include <string>
	#include <vector>





	//	Command tags.
	#define  CMD_PROMPED		"\n>"
	#define  CMD_ECHO			"echo"
	#define	 CMD_EXIT			"exit"
	#define	 CMD_ADD			"add"
	#define	 CMD_SUB			"sub"
	#define	 CMD_MUL			"mul"
	#define	 CMD_DIV			"div"




	//	Application command functions.
	bool CommandEcho(std::vector<std::string> params);
	bool CommandExit(std::vector<std::string> params);
	bool CommandAddition(std::vector<std::string> params);
	bool CommandSubtraction(std::vector<std::string> params);
	bool CommandMultiplying(std::vector<std::string> params);
	bool CommandDividing(std::vector<std::string> params);
#endif