#include"PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
    ;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm()
{
    *this = copy;
}
PresidentialPardonForm::~PresidentialPardonForm(void)
{
    ;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this == &copy)
        return (*this);
    AForm::operator=(copy);  
    return (*this);  
}