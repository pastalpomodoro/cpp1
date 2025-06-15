#include"PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
    ;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm()
{
    *this = copy;
}
PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name)
{
    ;
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

void PresidentialPardonForm::f() const{;}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &p)
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