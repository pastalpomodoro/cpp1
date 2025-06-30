#include"PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential", 25, 5)
{
    ;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm()
{
    *this = copy;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5)
{
    this->_target = target;
}
PresidentialPardonForm::~PresidentialPardonForm(void)
{
    ;
}
std::string PresidentialPardonForm::getTarget() const {
    return (this->_target);
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this == &copy)
        return (*this);
    this->_target = copy.getTarget();
    AForm::operator=(copy);
    return (*this);  
}

void PresidentialPardonForm::f(){;}

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