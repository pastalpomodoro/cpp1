#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _sign;
        const int           _exec;
    public:
        AForm(void);
        AForm(const AForm &copy);
        AForm(std::string name, int sign, int exec);
        virtual ~AForm(void);
        AForm &operator=(const AForm &copy);
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getSign(void) const;
        int getExec(void) const;
        
        void beSigned(Bureaucrat b);
        void execute(Bureaucrat const & executor) const;

        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw(){
                return ("AForm grade too hight execption");
            }
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw(){
                return ("AForm grade too low execption");
            }
        };
        class FormNotSigned : public std::exception
        {
            virtual const char *what() const throw(){
                return ("AForm not signed");
            }
        };
        virtual void f(void) = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);
#endif