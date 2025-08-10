#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T *a, int size, Func f)
{
    for (int i = 0; i < size; i++){
        f(a[i]);
    }
}
template <typename T>
void upper (T &s){
    for (int i = 0; s[i]; i++){
        s[i] -= 32;
    }
}

template <typename T>
void print(T const &x){
    std::cout << x << " ";
}
template <typename T>
void multi(T &x){
    x *= 10;
}
#endif