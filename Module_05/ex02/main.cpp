#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void){
	Bureaucrat b(71);
	RobotomyRequestForm r("tomatos");
	
	b.signAForm(r);

	std::cout << r << std::endl;
}