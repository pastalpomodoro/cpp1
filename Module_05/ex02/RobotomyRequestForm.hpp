#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include"AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm(std::string name);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        void f();
};
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &p);

#endif