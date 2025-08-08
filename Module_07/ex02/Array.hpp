#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T *_data;
        unsigned int _size;
    public:
        Array();
        Array(const Array &copy);
        ~Array();
        Array &operator=(const Array &copy);
};

#endif