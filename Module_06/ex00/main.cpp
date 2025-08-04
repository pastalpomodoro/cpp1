#include "ScalarConverter.hpp"

int main(void)
{
	std::string s = "";
	while (s != "q" && s != "Q"){
		std::getline(std::cin, s);
		std::cout << "-------------------------------------\n";
		ScalarConverter::convert(s);
	}
}