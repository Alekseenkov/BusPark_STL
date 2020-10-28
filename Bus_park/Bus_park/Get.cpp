

#include "Get.h"
#define Fullname "[\\A-Z]{1}""[\\w]+""( )""[A-Z]{1}""(.)""[A-Z]{1}""(.)"


std::string Get::_full_name()
{
	std::regex regular(Fullname);
	std::cmatch rez;
	std::string str, str1;
	while (true)
	{
		std::cin >> str >> str1;
		str = str + ' ' + str1;
		if (std::regex_match(str.c_str(), rez, regular))
			return str;
		else
			std::cout << "\nInput Error! Enter full name.\n";
	}

}

int Get::_int()
{
	std::regex regular("[\\d]{1,5}");
	std::cmatch rez;
	std::string str;
	while (true)
	{
		std::cin >> str;
		if (std::regex_match(str.c_str(), rez, regular))
			return std::stoi(str);
		else
			std::cout << "\nInput Error! Enter integer.\n";
	}
}
