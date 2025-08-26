#include "ScalarConverter.hpp"

int main(void)
{
	float f = 12.3f;
	(void)f;
	std::string s = "";
	while (s != "q" && s != "Q"){
		std::getline(std::cin, s);
		// s = "-4.5";
		std::cout << "-------------------------------------\n";
		ScalarConverter::convert(s);
	}
}