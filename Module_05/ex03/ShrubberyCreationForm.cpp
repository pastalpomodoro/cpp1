#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shruberry", 145, 137)
{
    ;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm()
{
    *this = copy;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shruberry", 145, 137)
{
    this->_target = target;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    ;
}
std::string ShrubberyCreationForm::getTarget() const {
    return (this->_target);
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this == &copy)
        return (*this);
    this->_target = copy.getTarget();
    AForm::operator=(copy);
    return (*this);
}

void ShrubberyCreationForm::f(){;}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &p)
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