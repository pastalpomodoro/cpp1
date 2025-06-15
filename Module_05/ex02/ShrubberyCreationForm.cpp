#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
    ;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm()
{
    *this = copy;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name)
{
    ;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    ;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this == &copy)
        return (*this);
    AForm::operator=(copy);
    return (*this);
}

void ShrubberyCreationForm::f() const{;}

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