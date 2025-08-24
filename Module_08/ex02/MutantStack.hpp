#ifndef MUNTANTSTACK
#define MUNTANTSTACK

#include<stack>
#include<iostream>
#include<deque>

template<typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
    public:
        typedef typename std::deque<T>::iterator                iterator;
        typedef typename std::deque<T>::const_iterator          const_iterator;
        typedef typename std::deque<T>::reverse_iterator        reverse_iterator;
        typedef typename std::deque<T>::const_reverse_iterator  const_reverse_iterator;
        MutantStack(void){};
        ~MutantStack(void){};
        MutantStack<T>::iterator begin(void)
        {
            return (this->c.begin());
        }
        MutantStack<T>::iterator end(void)
        {
            return (this->c.end());
        }

        MutantStack<T>::const_iterator begin(void) const
        {
            return (this->c.begin());
        }
        MutantStack<T>::const_iterator end(void) const
        {
            return (this->c.end());
        }   

        MutantStack<T>::reverse_iterator rbegin(void)
        {
            return (this->c.begin());
        }
        MutantStack<T>::reverse_iterator rend(void)
        {
            return (this->c.end());
        }

        MutantStack<T>::const_reverse_iterator rbegin(void) const
        {
            return (this->c.begin());
        }
        MutantStack<T>::const_reverse_iterator rend(void) const
        {
            return (this->c.end());
        }
};

#endif