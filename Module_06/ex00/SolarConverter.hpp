#ifndef SOLARCONVERTER_HPP
#define SOLARCONVERTER_HPP

#include <stdlib.h>
#include <iostream>

class SolarConverter
{
	private:
		SolarConverter(void);
		SolarConverter(const SolarConverter &copy);
		~SolarConverter(void);
		SolarConverter &operator=(const SolarConverter &copy);
	public:
		static void convert(std::string str);
};
#endif