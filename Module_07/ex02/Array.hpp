#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>

template <typename T>
class Array
{
    private:
        T*           _data;
        unsigned int _size;
    public:
        Array<T>(void) : _data(NULL), _size(0) {}
        Array<T>(const Array &copy){*this = copy;}
        Array<T>(unsigned int n) : _data(new T[n]) {}
        Array<T>(T* data, unsigned int x) : _data(new T[x]), _size(x) {
            for (unsigned int i = 0; i < this->_size; i++){
                this->_data[i] = data[i];
            }
        }
        ~Array<T>(void){delete [] _data;}
        Array &operator=(const Array &copy){
            if (this == &copy)
                return (*this);
            this->_size = copy._size;
            if (this->_data != NULL)
                delete this->_data;
            this->_data = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; i++){
                this->_data[i] = copy._data[i];
            }
            return (*this);
        }
        T&      operator[](const unsigned int index){
            if (index >= this->_size)
                throw Array::OutOfBoundsException();
            return (this->_data[index]);
        }
        class OutOfBoundsException : public std::exception
        {
            virtual const char *what() const throw(){
                return ("Out Of Bounds Exception");
            }
        };
        unsigned int size(void);
        void    setData(T *x);
        T*      getData(void);
        void    showData(void);
};

template <typename T>
unsigned int Array<T>::size(void){
    return (this->_size);
}
template <typename T>
void    Array<T>::showData(void)
{
    for (unsigned int i = 0; i < this->_size; i++){
        std::cout << this->_data[i] << std::endl;
    }
}

template <typename T>
void    Array<T>::setData(T *x)
{
    for (unsigned int i = 0; i < this->_size; i++){
        this->_data[i] = x[i];
    }
}

template <typename T>
T*  Array<T>::getData(void)
{
    return (this->_data);
}
#endif  