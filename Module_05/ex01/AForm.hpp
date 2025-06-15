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
        virtual ~AForm(void);
        AForm &operator=(const AForm &copy);
        // void operator<<(const AForm &x);
        virtual void f() const = 0;
};

#endif