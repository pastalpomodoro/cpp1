#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include<ostream>
#include<stack>
#include<sstream>

class RPN
{
    private:
        std::stack<int>  _stack;
    public:
        RPN(void);
        RPN(const RPN &copy);
        ~RPN(void);
        RPN& operator=(const RPN &copy);

        int     calcul(int a, int b, std::string token);
        bool    isOperator(std::string token);
        void    calculator(std::string line);
};

#endif