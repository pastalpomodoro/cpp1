#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>

class Base {
public:
    Base();
    Base(const Base &copy);
    virtual ~Base();
};

#endif