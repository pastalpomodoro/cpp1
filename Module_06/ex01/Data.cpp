#include "Data.hpp"

Data::Data(){;}
Data::Data(const Data &copy){
    *this = copy;
}
Data::~Data(void){;}
Data& Data::operator=(const Data &copy){
    if (this == &copy)
        return (*this);
    this->_s = copy._s;
    return (*this);
}
void    Data::setValue(std::string s)
{
    this->_s = s;
}
std::string Data::getValue(){return(this->_s);}