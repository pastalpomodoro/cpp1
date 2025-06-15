#include"AForm.hpp"

AForm::AForm(void) : _sign(false)
{
    std::cout << "AForm Defoault constructor called\n";
}
AForm::AForm(const AForm &copy)
{
    std::cout << "AForm Defoault constructor called\n";
    *this = copy;
}
AForm::~AForm(void)
{
    std::cout << "AForm Destructor called\n";
}
AForm &AForm::operator=(const AForm &copy)
{
    if (this == &copy)
        return (*this);
    this->_exec = copy._exec;
    this->_sign = copy._sign;
}