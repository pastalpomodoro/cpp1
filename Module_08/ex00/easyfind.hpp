#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include<iostream>

class NoOccurenceException : public std::exception
{
    virtual const char *what() const throw(){
        return ("No occurence found!!");
    }
};

template<typename T>
typename T::const_iterator easyfind(T const &x, int const n){
    typename T::const_iterator it;
    it = std::find(x.begin(), x.end(), n);
    if (it == x.end())
        throw NoOccurenceException();
    return (it);
}


#endif