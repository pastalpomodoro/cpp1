#include"RPN.hpp"

RPN::RPN(void){;}

RPN::RPN(std::string av) : _status(false)
{
    std::istringstream ill(av);
    std::string temp;

    for (int i = 0; std::getline(ill, temp, ' '); i++){
        for (int j = 0; temp[j]; j++){
            if (!isdigit(temp[j]) && (temp.length() > 1 || (temp[0] != '+' && temp[0] != '-'
                && temp[0] != '*' && temp[0] != '/'))){
                std::cout << "error: only 123456789 +-*/ " << temp << std::endl;
                return ;
            }
        }
        if (isdigit(temp[0]))
            this->_numDeque.push_back(std::atoi(temp.c_str()));
        else{
            this->_strDeque.push_back(temp);
            this->_index.push_back(i);
        }
    }
    for (size_t i = 0; i < this->_numDeque.size(); i++){
        std::cout << this->_numDeque[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < this->_index.size(); i++){
        std::cout << this->_index[i] << " ";
    }
    std::cout << std::endl << std::endl;
    this->_status = true;
}

RPN::RPN(const RPN &copy){
    *this = copy;
}
RPN::~RPN(void){;}
RPN& RPN::operator=(const RPN &copy){
    if (this == &copy)
        return (*this);
    this->_numDeque = copy._numDeque;
    this->_strDeque = copy._strDeque;
    return (*this);
}

// void    RPN::calculator(){
//     int index;
//     int x;
//     int y;

//     for (size_t i = 0; i < this->_index.size(); i++){
//         index = this->_index[i];
//         index--;
//         if (this->_numDeque.size() > 1 && index > 0 ){
//             std::cout << this->_numDeque.size() << " " << index << std::endl;
//             x = this->_numDeque[index - 1];
//             y = this->_numDeque[index];
//             if (this->_strDeque[i] == "+")
//                 this->_numDeque[index] = x + y;
//             else if (this->_strDeque[i] == "-")
//                 this->_numDeque[index] = x - y;
//             else if (this->_strDeque[i] == "*")
//                 this->_numDeque[index] = x * y;
//             else if (this->_strDeque[i] == "/")
//                 this->_numDeque[index] = x / y;
//             this->_numDeque.erase(this->_numDeque.begin() + index - 1);

//         }
//         // if (this->_numDeque.size() == 1){
//         //     std::cout << "result: " << this->_numDeque[0] << std::endl;
//         //     return;
//         // }
//         // else{
//         //     std::cerr << "error: bad input\n";
//         // }
//         //     return;
//         std::cout << this->_numDeque[0] << std::endl;
//         for (size_t j = 0; j < this->_index.size(); j++)
//             this->_index[j]-=2;
//     }
//     if (this->_numDeque.size() != 1)
//         std::cout << "erro: bad input\n";
//     else
//         std::cout << "result: " << this->_numDeque[0] << std::endl;
// }