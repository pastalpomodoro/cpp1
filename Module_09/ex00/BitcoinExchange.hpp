#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<stdlib.h>

class BitcoinExchange
{
    private:
        std::map<std::string, double>   btc;
        std::ifstream                   input;
        std::string                     date;
        double                          num;
        int                             inYear;
        int                             inMonth;
        int                             inDay;
    public:
        BitcoinExchange(char *av);
        BitcoinExchange(BitcoinExchange const &copy);
        ~BitcoinExchange(void);
        BitcoinExchange& operator=(const BitcoinExchange &copy);

        void    finder();
        bool    checkDate();
        bool    checkNum(std::string temp1, std::string line);
        bool    findDate();
        bool    isSmallerDate(std::string date);
        void    setDates();
};

#endif