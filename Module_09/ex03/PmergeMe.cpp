#include"PmergeMe.hpp"

Pmerge::Pmerge(void){}

Pmerge::Pmerge(std::string s){}
Pmerge::Pmerge(const Pmerge &copy){
    *this = copy;
}
Pmerge::~Pmerge(void){}
Pmerge& Pmerge::operator=(const Pmerge& copy){
    if (this == &copy)
        return (*this);
    return (*this);
}