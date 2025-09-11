#include"RPN.hpp"

RPN::RPN(void){;}

RPN::RPN(const RPN &copy){
    *this = copy;
}
RPN::~RPN(void){;}
RPN& RPN::operator=(const RPN &copy){
    if (this == &copy)
        return (*this);
    return (*this);
}

void    RPN::calculator(std::string line)
{
    std::istringstream  ill(line);
    std::string         temp;
    while (std::getline(ill, temp, ' '))
    {
        if (this->_stack.size() > 0)
            std::cout << "num: " <<this->_stack.top() <<std::endl;
        if (isdigit(temp[0]) || (temp[0] == '-' && temp.length() > 1)){
            for (int i = 0; temp[i]; i++){
                if (i == 0 && temp[i] == '-')
                    continue;
                else if (!isdigit(temp[i]))
                    throw std::runtime_error("only digit or operators");
            }
            this->_stack.push(atoi(temp.c_str()));
        }
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