#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Lucie"), _grade(12){}
Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name)
{
    *this = copy;
}
Bureaucrat::Bureaucrat(int grade): _name("Lucie")
{
    this->_grade = grade;
}
Bureaucrat::Bureaucrat(std::string name, int x): _name(name)
{
    std::cout << "Bureaucrat copy constructor called\n";
    this->_grade = x;
}
Bureaucrat::~Bureaucrat(void){}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this == &copy)
        return (*this);
    this->_grade = copy._grade;
    return (*this);
}
std::string Bureaucrat::getName(void) const
{
    return(this->_name);
}
int Bureaucrat::getGrade(void) const
{
    return(this->_grade);
}
void Bureaucrat::incrementGrade(int x)
{
    if (this->_grade - x < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade -= x;
}

void Bureaucrat::decrementGrade(int x)
{
    if (this->_grade + x > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade += x;
}
void Bureaucrat::signAForm(AForm &AForm)
{
    try{
        AForm.beSigned(*this);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}
void Bureaucrat::executeForm(AForm const &form)
{
    try{
        form.execute(*this);
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}