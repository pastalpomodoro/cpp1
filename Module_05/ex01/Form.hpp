#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        std::string _name;
        bool _signed;
        int const _sign;
        int const _exec;
    public:
        Form(void);
        Form(const Form &copy);
        Form(std::string name);
        ~Form(void);
        Form &operator=(const Form &copy);
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getSign(void) const;
        int getExec(void) const;
        void beSigned(Bureaucrat b);

        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw(){
                return ("Form grade too hight execption");
            }
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw(){
                return ("Form grade too low execption\n");
            }
        };
};

std::ostream &operator<<(std::ostream &os, const Form &f);
#endif