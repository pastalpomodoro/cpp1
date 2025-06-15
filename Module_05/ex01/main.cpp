#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    PresidentialPardonForm a("Luca");
    RobotomyRequestForm b("Fererico");
    ShrubberyCreationForm c("Alberto");

    std::cout << a <<std::endl;
    std::cout << b <<std::endl;
    std::cout << c <<std::endl;
}