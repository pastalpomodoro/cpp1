#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;
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
        std::string getName(void);
        int getGrade(void);
        void incrementGrade(int x);
        void decrementGrade(int x);

        void signAForm(AForm &AForm);

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

#endif