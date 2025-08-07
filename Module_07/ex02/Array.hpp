#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array
{
    public:
        Array();
        Array(const Array &copy);
        ~Array();
        Array &operator=(const Array &copy);
}

#endif