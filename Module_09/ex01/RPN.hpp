#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include<deque>
#include<sstream>

class RPN
{
    private:
        std::deque<int>         _numDeque;
        std::deque<int>         _index;
        std::deque<std::string> _strDeque;
        bool                    _status;
    public:
        RPN(void);
        RPN(std::string av);
        RPN(const RPN &copy);
        ~RPN(void);
        RPN& operator=(const RPN &copy);

        void calculator();
};

#endif