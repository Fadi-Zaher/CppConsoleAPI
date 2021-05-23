#ifndef COMMAND_H
#define COMMAND_H




	/***
	* Include files.
	*/
	#include <map>
	#include <vector>
	#include <string>






	/***
	* Command function pointer data type.
	*/
	typedef bool (*CommandCb)(std::vector<std::string> params);





	/***
	* Commands list Class
	* Contains a list of commands indexed by name
	* providing command execution API.
	*/
	class Commands
	{
		// Commands dioctionary containing command callbacks indexted by command name.
		private:	std::map<std::string, CommandCb> commands_dic;

		//	Class constructor/distructor.
		public:	Commands();
		public:	~Commands();

		//	Add new command to list.
		public:	bool			Add(std::string name, CommandCb& pCallback);

		// Find command clallback function.
		public:	CommandCb* Find(std::string name);

		//	Call for command execution.
		public:	bool			Exec(std::string name, std::vector<std::string> params);
	};

#endif // !COMMAND_H
