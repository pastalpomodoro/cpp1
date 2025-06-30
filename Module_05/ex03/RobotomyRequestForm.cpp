#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy", 72, 45)
{
    ;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm()
{
    *this = copy;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45)
{
    this->_target = target;
}
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    ;
}

std::string RobotomyRequestForm::getTarget() const{
    return (this->_target);
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this == &copy)
        return (*this);
    this->_target = copy.getTarget();
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