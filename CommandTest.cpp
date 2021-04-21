
#include "CppUnitTest.h"
#include "../CppConsoleAPI/Command.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;




#define	CMD_ECHO	"ecco"
bool CommandEcho(std::vector<std::string> params)
{
	return(true);
}





namespace CppCommandTest
{

	TEST_CLASS(CppCommandTest)
	{
	public:
		
		TEST_METHOD(TestCommand)
		{
			Commands* pCommands = CommandsInit();
			Assert::IsNotNull(pCommands);

			Assert::IsTrue(CommandAdd(pCommands, CMD_ECHO, CommandEcho));

		}
	};
}
