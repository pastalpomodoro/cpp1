#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <stdlib.h>
#include <iostream>
#include <climits>
#include <cerrno>
#include <cfloat>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter(void);
		ScalarConverter &operator=(const ScalarConverter &copy);
	public:
		static void		convert(std::string str);

		static void		printChar(char str);
		static void		printInt(int str);
		static void		printFloat(float str);
		static void		printDouble(double str);
		static void		printSimbol(std::string str);
};
#endif