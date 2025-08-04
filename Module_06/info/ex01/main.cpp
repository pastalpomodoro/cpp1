/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:06:43 by alacroix          #+#    #+#             */
/*   Updated: 2025/06/19 12:17:59 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data *before = new Data(42);
	std::cout << "Data->getValue() = "<< before->getValue() << std::endl;

	uintptr_t raw_data = Serializer::Serialize(before);

	Data *after = Serializer::deserialize(raw_data);
	std::cout << "Data->getValue() = " << after->getValue() << std::endl;

	delete after;
}
