#include "SolarConverter.hpp"

int main(void)
{
	std::string s = "";
	while (s != "q" && s != "Q"){
		std::getline(std::cin, s);
		SolarConverter::convert(s);
	}
}