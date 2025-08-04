#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer(void);
        Serializer(const Serializer &copy);
        ~Serializer(void);
        Serializer& operator=(const Serializer &copy);
    public:
        static uintptr_t   serialize(Data *ptr);
        static Data*       deserialize(uintptr_t raw);
};
#endif