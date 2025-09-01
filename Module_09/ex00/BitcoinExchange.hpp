#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include<iostream>
#include<map>

class BitcoinExchange
{
    public:
        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const &copy);
        ~BitcoinExchange(void);
        BitcoinExchange& operator=(const BitcoinExchange &copy);
};

#endif