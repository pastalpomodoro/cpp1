#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include"AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm(std::string name);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        void f();
};
std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &p);

#endif