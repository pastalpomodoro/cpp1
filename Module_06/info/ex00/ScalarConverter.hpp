/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:31:03 by alacroix          #+#    #+#             */
/*   Updated: 2025/06/19 11:12:44 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <cfloat>

class ScalarConverter
{
	public:
		static void convert(std::string literal);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		~ScalarConverter();

		ScalarConverter &operator=(ScalarConverter const &other);

		static bool isCharLiteral(std::string &literal);
		static bool isPseudoLiteral(std::string &literal);

		static void fromChar(char c);
		static void fromInt(int i);
		static void fromFloat(float f);
		static void fromDouble(double d);
		static void fromPseudoLiteral(std::string &literal);
};

#endif
