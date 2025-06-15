#ifndef AFORM_HPP
#define AFORM_HPP

#include<iostream>

class AForm
{
    private:
        std::string _name;
        bool _signed;
        const int _sign;
        const int _exec;
    public:
        AForm(void);
        AForm(const AForm &copy);
        virtual ~AForm(void);
        AForm &operator=(const AForm &copy);
        virtual void f() const = 0;
};

#endif