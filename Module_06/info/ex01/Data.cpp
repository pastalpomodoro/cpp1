/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:43:48 by alacroix          #+#    #+#             */
/*   Updated: 2025/06/19 11:47:13 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data():_value(0)
{}

Data::Data(int value) : _value(value)
{}

Data::Data(Data const &other) : _value(other._value)
{}

Data::~Data()
{}

Data &Data::operator=(Data const &other)
{
	if(this != &other)
		this->_value = other._value;
	return *this;
}

int Data::getValue() const
{
	return this->_value;
}
