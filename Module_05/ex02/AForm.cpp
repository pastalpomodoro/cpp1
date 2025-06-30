#include"AForm.hpp"

AForm::AForm(void) : _name("Basic_AForm"), _signed(false), _sign(100), _exec(100)
{
    // std::cout << "AForm Defoault constructor called\n";
}
AForm::AForm(std::string name, int sign, int exec) : _name(name), _signed(false), _sign(sign), _exec(exec)
{
    ;
}
AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _sign(copy._sign), _exec(copy._exec)
{
    // std::cout << "AForm Defoault constructor called\n";
}
AForm::~AForm(void)
{
    // std::cout << "AForm Destructor called\n";
}
AForm &AForm::operator=(const AForm &copy)
{
    if (this == &copy)
        return (*this);
    this->_name = copy._name;
    this->_signed = copy._signed;
    return (*this);
}

std::string AForm::getName(void) const{
    return(this->_name);
}
bool AForm::getIsSigned(void) const{
    return(this->_signed);
}
int AForm::getSign(void) const{
    return(this->_sign);
}
int AForm::getExec(void) const{
    return(this->_exec);
}

void AForm::beSigned(Bureaucrat b)
{
    if (this->_sign >= b.getGrade()){
        this->_signed = true;
        std::cout << b.getName() << " signed " << this->_name << std::endl;
    }
    else{
        std::cout << b.getName() << " couldn't sign " << this->_name <<  " because ";
        throw AForm::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << f.getName() << " ";
    if (f.getIsSigned() == false)
        os << "Isn't signed ";
    else
        os << "Is signed ";
    return (os);
}
