#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm()
{
    ;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm()
{
    *this = copy;
}
RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{
    ;
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

void RobotomyRequestForm::f() {;}
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &p)
{
    os << p.getName();
    if (p.getIsSigned() == false)
        os << " isn't signed";
    else
        os << " is signed";
    os << ", need " << p.getExec() << " to execute";
    os << " and " << p.getSign() << " to signe.";
    return(os);
}