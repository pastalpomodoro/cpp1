#ifndef AFORM_HPP
#define AFORM_HPP

#include<iostream>

class AForm
{
    private:
        std::string _name;
        bool _signed;
        int const _sign;
        int const _exec;
    public:
        AForm(void);
        AForm(const AForm &copy);
        AForm(std::string name);
        virtual ~AForm(void);        
        AForm &operator=(const AForm &copy);
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getSign(void) const;
        int getExec(void) const;
        virtual void f(void) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);
#endif