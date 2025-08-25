#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    private:
        const std::string _name;
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

        void signAForm(AForm &AForm);
        void executeForm(AForm const & form);

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
                return("Grade Too Low Excetpion\n");
            } 
        };
};
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif