#include"RPN.hpp"

RPN::RPN(void){;}

RPN::RPN(const RPN &copy){
    *this = copy;
}
RPN::~RPN(void){;}
RPN& RPN::operator=(const RPN &copy){
    if (this == &copy)
        return (*this);
    this->_stack = copy._stack;
    return (*this);
}

void    RPN::calculator(std::string line)
{
    std::istringstream  ill(line);
    std::string         temp;
    while (std::getline(ill, temp, ' '))
    {
        if (isdigit(temp[0]) && temp.size() == 1)
            this->_stack.push(temp[0] - '0');
        else if (isdigit(temp[1]) && temp.size() == 2 && temp[0] == '-')
            this->_stack.push((temp[1] - '0')*-1);
        else if (isOperator(temp)){
            if (this->_stack.size() < 2)
                throw std::runtime_error("too much operator");
            int b = this->_stack.top();
            this->_stack.pop();
            int a = this->_stack.top();
            this->_stack.pop();
            this->_stack.push(calcul(a, b, temp));
        }
        else
            throw std::runtime_error("only digit or operators");
    }
    if (this->_stack.size() != 1)
        throw std::runtime_error("too much numbers");
    std::cout << this->_stack.top() << std::endl;
}

int     RPN::calcul(int a, int b, std::string token)
{
    if (token == "+") return (a + b);
    if (token == "-") return (a - b);
    if (token == "*") return (a * b);
    if (token == "/")
    {
        if (b == 0)
            throw std::runtime_error("error");
        return (a / b);
    }
    throw std::runtime_error("error");
}

bool     RPN::isOperator(std::string token)
{
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return (true);
    return (false);
}