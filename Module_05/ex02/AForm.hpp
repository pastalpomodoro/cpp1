#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
    private:
        std::string _name;
        bool _signed;
        int const _sign;
        int const _exec;
    public:
        AForm(void);
        AForm(const AForm &copy);
        AForm(std::string name, int sign, int exec);
        ~AForm(void);
        AForm &operator=(const AForm &copy);
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getSign(void) const;
        int getExec(void) const;
        void beSigned(Bureaucrat b);

        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw(){
                return ("AForm grade too hight execption");
            }
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw(){
                return ("AForm grade too low execption\n");
            }
        };
        virtual void f(void) = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);
#endif