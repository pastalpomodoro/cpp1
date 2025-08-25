#include"Form.hpp"

Form::Form(void) : _name("Basic_Form"), _signed(false), _sign(150), _exec(150)
{
    // std::cout << "Form Defoault constructor called\n";
}
Form::Form(std::string name, int sign) : _name(name), _signed(false), _sign(sign), _exec(150)
{
    ;
}
Form::Form(const Form &copy) : _name(copy._name), _sign(copy._sign), _exec(copy._exec)
{
    *this = copy;
}
Form::~Form(void)
{
    // std::cout << "Form Destructor called\n";
}
Form &Form::operator=(const Form &copy)
{
    if (this == &copy)
        return (*this);
    this->_signed = copy._signed;
    return (*this);
}

std::string Form::getName(void) const{
    return(this->_name);
}
bool Form::getIsSigned(void) const{
    return(this->_signed);
}
int Form::getSign(void) const{
    return(this->_sign);
}
int Form::getExec(void) const{
    return(this->_exec);
}

void Form::beSigned(Bureaucrat b)
{
    if (this->_sign >= b.getGrade()){
        this->_signed = true;
        std::cout << b.getName() << " signed " << this->_name << std::endl;
    }
    else{
        std::cout << b.getName() << " couldn't sign " << this->_name <<  " because ";
        throw Form::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << f.getName() << " ";
    if (f.getIsSigned() == false)
        os << "Isn't signed, need grade " << f.getSign() << " to be signed";
    else
        os << "Is signed ";
    return (os);
}
