#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Lucie"), _grade(12)
{
    // std::cout << "Bureaucrat default constructor called\n";
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    // std::cout << "Bureaucrat assignement constructor called\n";
    *this = copy;
}
Bureaucrat::Bureaucrat(int grade): _name("Lucie")
{
    // std::cout << "Bureaucrat copy constructor called\n";
    this->_grade = grade;
}
Bureaucrat::~Bureaucrat(void)
{
    // std::cout << "Bureaucrat destructor called\n";
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this == &copy)
        return (*this);
    this->_grade = copy._grade;
    this->_name = copy._name;
    return (*this);
}
std::string Bureaucrat::getName(void) const
{
    // std::cout << ", bureaucrat name: " << this->_name;
    return(this->_name);
}
int Bureaucrat::getGrade(void) const
{
    // std::cout << this->_name << ", bureaucrat grade " << this->_grade << ".\n";
    return(this->_grade);
}
void Bureaucrat::incrementGrade(int x)
{
    if (this->_grade + x > 150)
        throw Bureaucrat::GradeTooHighException();
    this->_grade += x;
}

void Bureaucrat::decrementGrade(int x)
{
    if (this->_grade - x < 1)
        throw Bureaucrat::GradeTooLowException();
    this->_grade -= x;
}
void Bureaucrat::signForm(Form &form)
{
    try{
        form.beSigned(*this);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}