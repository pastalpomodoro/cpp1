#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm()
{
    ;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm()
{
    *this = copy;
}
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    ;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this == &copy)
        return (*this);
    AForm::operator=(copy);
    return (*this);
}
