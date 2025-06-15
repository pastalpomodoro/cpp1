#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
    ;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm()
{
    *this = copy;
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