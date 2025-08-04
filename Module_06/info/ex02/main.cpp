/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:18:38 by alacroix          #+#    #+#             */
/*   Updated: 2025/06/19 15:00:07 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "ctime"
#include "cstdlib"

Base *generate()
{
	std::srand(std::time(NULL));
	int choice = rand() % 3;

	if(choice == 0)
	{
		A *objectA = new A;
		return dynamic_cast<Base*>(objectA);
	}
	else if(choice == 1)
	{
		B *objectB = new B;
		return dynamic_cast<Base*>(objectB);
	}
	else
	{
		C *objectC = new C;
		return dynamic_cast<Base*>(objectC);
	}
}

void identify(Base *p)
{
	if(!p)
		std::cout << "NULL ptr" << std::endl;
	if(dynamic_cast<A*>(p))
		std::cout << "Object type is A" << std::endl;
	if(dynamic_cast<B*>(p))
		std::cout << "Object type is B" << std::endl;
	if(dynamic_cast<C*>(p))
		std::cout << "Object type is C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &casted = dynamic_cast<A&>(p);
		(void)casted;
		std::cout << "Object type is A" << std::endl;
	}
	catch(...)
	{
	}
	try
	{
		B &casted = dynamic_cast<B&>(p);
		(void)casted;
		std::cout << "Object type is B" << std::endl;
	}
	catch(...)
	{
	}
	try
	{
		C &casted = dynamic_cast<C&>(p);
		(void)casted;
		std::cout << "Object type is C" << std::endl;
	}
	catch(...)
	{
	}
}

int main()
{
	Base *randomObject = generate();
	Base &randomObjectRef = *randomObject;

	identify(randomObject);
	identify(randomObjectRef);

	delete randomObject;
}
