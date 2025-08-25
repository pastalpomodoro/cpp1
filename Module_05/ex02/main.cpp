#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void){
	Bureaucrat b(46);
	RobotomyRequestForm r;
	ShrubberyCreationForm s;
	PresidentialPardonForm p;
	

	std::cout << b <<std::endl << std::endl;
	std::cout << r <<std::endl;
	b.signAForm(r);
	b.executeForm(r);
	std::cout <<"------------------------------------------" << std::endl;
	std::cout << s <<std::endl;
	b.signAForm(s);
	b.executeForm(s);
	std::cout <<"------------------------------------------" << std::endl;
	std::cout << p <<std::endl;
	b.signAForm(p);
	b.executeForm(p);
}