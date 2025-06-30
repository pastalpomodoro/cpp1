#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;
class Bureaucrat
{
    private:
        std::string _name;
        int _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat(int grade);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat(void);
        std::string getName(void) const;
        int getGrade(void) const;
        void incrementGrade(int x);
        void decrementGrade(int x);

        void signForm(Form &form);

        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return("Grade Too High Excetpion\n");
            } 
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return("Grade Too High Excetpion\n");
            } 
        };
};
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif