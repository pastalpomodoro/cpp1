#include"Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void){
	;
}
Intern::Intern(const Intern &copy){
	*this = copy;
}
Intern::~Intern(void){
	;
}

Intern &Intern::operator=(const Intern &copy){
	if (this == &copy)
		return (*this);
	return (*this);
}

AForm *makep(std::string target){
	return (new PresidentialPardonForm(target));
}
AForm *makes(std::string target){
	return (new ShrubberyCreationForm(target));
}
AForm *maker(std::string target){
	return (new RobotomyRequestForm(target));
}
AForm *Intern::makeForm(std::string form, std::string target)
{
	AForm *(*ff[])(std::string target) = {&maker, &makep, &makes};
	std::string forms[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for (int i = 0; i < 3; i++){
		if (form == forms[i])
			return (ff[i](target));
	}
	std::cout << "Aucune form trouve\n";
	return (NULL);
}