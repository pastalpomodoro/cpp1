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
#endif