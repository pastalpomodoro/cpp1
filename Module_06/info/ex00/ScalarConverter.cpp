/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:37:39 by alacroix          #+#    #+#             */
/*   Updated: 2025/06/19 11:23:27 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter const &other){(void)other;}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other){(void)other;return *this;}

void ScalarConverter::convert(std::string literal)
{
	char *endptr;

	if (isPseudoLiteral(literal))
		return fromPseudoLiteral(literal);

	if (isCharLiteral(literal))
		return fromChar(literal[0]);

	endptr = NULL;
	errno = 0;
	long lValue = std::strtol(literal.c_str(), &endptr, 10);
	if (*endptr == '\0' && (INT_MIN <= lValue && INT_MAX >= lValue) && errno != ERANGE)
		return fromInt(static_cast<int>(lValue));

	errno = 0;
	endptr = NULL;
	float fValue = std::strtof(literal.c_str(), &endptr);
	if (*endptr == 'f' && *(endptr + 1) == '\0' && (fValue < FLT_MAX && fValue > -FLT_MAX) && errno != ERANGE)
		return fromFloat(fValue);

	errno = 0;
	endptr = NULL;
	double dValue = std::strtod(literal.c_str(), &endptr);
	if (*endptr == '\0' && errno != ERANGE)
		return fromDouble(dValue);

	std::cout << "Invalid literal" << std::endl;
}

bool ScalarConverter::isCharLiteral(std::string &literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::isPseudoLiteral(std::string &literal)
{
	return (literal == "nan" || literal == "nanf" || literal == "+inf"
		|| literal == "+inff" || literal == "-inf" || literal == "-inff");
}

void ScalarConverter::fromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::fromInt(int i)
{
	std::cout << "I: " << i << std::endl;
	if( i > 31 && i < 127)
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::fromFloat(float f)
{
	if(f > 31 && f < 127 && std::isprint(static_cast<int>(f)))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if(-2147483648.0 <= f && f <= 2147483647.0)
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::fromDouble(double d)
{
	if(d > 31 && d < 127 && std::isprint(static_cast<int>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if(INT_MIN <= d && INT_MAX >= d)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::fromPseudoLiteral(std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if(literal[literal.length() - 2] == 'f')
	{
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
	}
	else
	{
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
}
