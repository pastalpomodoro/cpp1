#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void){;}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}
BitcoinExchange::~BitcoinExchange(void){;}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy){
    if (this == &copy)
        return (*this);
    return (*this);
}
