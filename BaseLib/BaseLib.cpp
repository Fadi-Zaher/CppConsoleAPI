/***
* Include files.
*/
//#include <iostream>
#include <string>
#include <regex>





/***
* Trim left white spaces by replasing with empty string.
*/
std::string ltrim(const std::string& s)
{
   return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}

/***
* Trim righ white spaces by replasing with empty string.
*/
std::string rtrim(const std::string& s)
 {
   return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}

/***
* Trim left and right using trim functions.
*/
std::string trim(const std::string& s)
{
   return ltrim(rtrim(s));
}

