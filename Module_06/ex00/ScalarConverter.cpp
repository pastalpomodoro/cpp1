#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){
	;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	*this = copy;
}

ScalarConverter::~ScalarConverter(void){
	;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy){
	if (this == &copy)
		return (*this);
	return (*this);
}

bool ScalarConverter::isCastable(std::string str){
	// for (int i = 0; str[i]; i++){
		
	// }
	return false;
	std::cout << str << std::endl;
	;
}

void	ScalarConverter::printChar(char str){
	std::cout << "char: " << str << std::endl;
	std::cout << "int: " << static_cast<int>(str) << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "float: " << static_cast<float>(str)<< "f" << std::endl;
	std::cout << "double: " << static_cast<double>(str) << std::endl;
}

void	ScalarConverter::printInt(int str){
	if (str > 31 && str != 127)
		std::cout << "char: " << static_cast<char>(str) << std::endl;
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << str << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);	
	std::cout << "float: " << static_cast<float>(str) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(str) << std::endl; 
}

void	ScalarConverter::printFloat(float str){
	if (str > 31 && str != 127)
		std::cout << "char: " << static_cast<char>(str) << std::endl;
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(str) << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);	
	std::cout << "float: " << str << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(str) << std::endl; 
}

void	ScalarConverter::printDouble(double str){
	if (str > 31 && str != 127)
		std::cout << "char: " << static_cast<char>(str) << std::endl;
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(str) << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);	
	std::cout << "float: " << static_cast<float>(str) << 'f' << std::endl;
	std::cout << "double: " << str << std::endl; 
}

void	ScalarConverter::printSimbol(std::string str){
	std::cout << "char: Non displayable\nint: Non displayable\n";
	std::cout << "float: " << str;
	if (str == "nan" || str == "+inf" || str == "-inf")
		std::cout << "f\ndouble: " << str << std::endl;	
	else
		std::cout << "\ndouble: " << str.substr(0, str.length() - 1) << std::endl;
}

void	ScalarConverter::convert(std::string str){
	char *endptr;

	if (str == "nan" || str == "nanf" || str == "+inf"
		|| str == "+inff" || str == "-inf" || str == "-inff")
		return printSimbol(str);

	if (str.length() == 1 && !std::isdigit(str[0]))
		return printChar(str[0]);
	
	errno = 0;
	endptr = NULL;
	long int l = std::strtol(str.c_str(), &endptr, 10);
	if (endptr[0] == '\0' && l >= INT_MIN && l <= INT_MAX && errno != ERANGE)
		return printInt(static_cast<int>(l));
	
	errno = 0;
	endptr = NULL;
	float f = std::strtof(str.c_str(), &endptr);
	if (endptr[0] == '\0' && errno != ERANGE && f <= FLT_MAX && f >= FLT_MIN)
		return printFloat(f);

	errno = 0;
	endptr = NULL;
	double d = std::strtod(str.c_str(), &endptr);
	if (endptr[0] == '\0' && errno != ERANGE && d >= DBL_MIN && f <= DBL_MAX)
		return printDouble(d);

	std::cout << "-------------------------------------\n";	
}