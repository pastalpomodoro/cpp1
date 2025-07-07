#include "SolarConverter.hpp"

SolarConverter::SolarConverter(void){
	;
}

SolarConverter::SolarConverter(const SolarConverter &copy){
	*this = copy;
}

SolarConverter::~SolarConverter(void){
	;
}

SolarConverter &SolarConverter::operator=(const SolarConverter &copy){
	if (this == &copy)
		return (*this);
	return (*this);
}

void SolarConverter::convert(std::string str){
	std::cout << atoi(str.c_str()) << std::endl;
}