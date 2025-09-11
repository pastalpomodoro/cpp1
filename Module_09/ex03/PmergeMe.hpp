#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<iostream>

class Pmerge
{
    private:
        std::vector<int>    stack;
    public:
        Pmerge(void);
        Pmerge(std::string s);
        Pmerge(const Pmerge &copy);
        ~Pmerge(void);
        Pmerge& operator=(const Pmerge &copy);
};

#endif