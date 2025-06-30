#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include"AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm(std::string name);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        void f();
};
std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &p);

#endif