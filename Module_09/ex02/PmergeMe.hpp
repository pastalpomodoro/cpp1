#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <deque>
template <typename T>
class PmergeMe
{
    private:
        size_t                              n_num;
        size_t                              nNumBlock;
        std::vector<T>                      main;
        std::vector<T>                      pend;
        T                                   trash;
    public:
        PmergeMe(void){}
        PmergeMe(char **av);
        PmergeMe(const PmergeMe &copy);
        ~PmergeMe(void){}
        PmergeMe& operator=(const PmergeMe &copy);

        void start();
        size_t binarySearch(size_t j, size_t l, size_t t);
        void blocking();
        void reverseBlocking();
        std::vector<T> &getMain();
};

// bool isSorted(std::vector<std::vector<int> > &v);
size_t jacobsthalNumber(size_t n);

template <typename T>
std::vector<T> &PmergeMe<T>::getMain(){return (this->main);}

template <typename T>
bool isSorted(std::vector<T > &v)
{   
    for (size_t i = 1; i < v.size() - 1; i++)
    {
        if (v[i].front() < v[i - 1].front())
            return false;
    }
    return true;
}
template <typename T>
PmergeMe<T>::PmergeMe(char **av)
{
    char *endptr;
    this->n_num = 1;
    this->nNumBlock = 0;
    for (; av[this->n_num]; this->n_num++){
        endptr = NULL;
        long int n = std::strtol(av[this->n_num], &endptr, 10);
        if (endptr[0] == '\0' && n <= 2147483647 && n >= 0)
            this->main.push_back(T(1, n));
        else
            throw std::runtime_error("only positif integers!!");
    }
    this->n_num--;
}
template <typename T>
void PmergeMe<T>::blocking()
{
    for (size_t i = 0; i < this->main.size(); i++){
        if (i < this->main.size() - 1){
            if (this->main[i].back() > this->main[i + 1].back() && this->main[i + 1].size() == this->main[i].size()){
                std::swap(this->main[i], this->main[i+1]);
            }
            this->main[i].insert(this->main[i].end(), this->main[i + 1].begin(), this->main[i + 1].end());
            this->main.erase(this->main.begin() + i + 1);
        }
    }
    if (this->main[0].size() < this->n_num / 2)
        return (this->blocking());
}
template <typename T>
void PmergeMe<T>::reverseBlocking()
{
    this->nNumBlock = this->main[0].size();
    this->main.insert(this->main.begin() + 1, T());
    this->main[1].insert(this->main[1].begin(), this->main[0].begin() + nNumBlock / 2, this->main[0].end());
    this->main[0].erase(this->main[0].begin() + nNumBlock / 2, this->main[0].end());
    for  (size_t i = 2; i < this->main.size(); i++)
    {
        if (this->main[i].size() >= nNumBlock / 2)
        {
            this->pend.push_back(T());
            this->pend[i-2].insert(this->pend[i-2].end(), this->main[i].begin(), this->main[i].begin() + nNumBlock / 2);
            this->main[i].erase(this->main[i].begin(), this->main[i].begin() + nNumBlock / 2);
        }
        if (this->main[i].size() < nNumBlock / 2){
            this->trash.insert(this->trash.begin(), this->main[i].begin(), this->main[i].end());
            this->main.pop_back();
        }
    }

    size_t i = 0;
    size_t pIndex = 0;
    for (int j = 3; this->pend.size() > 0; j++)
    {
        pIndex = jacobsthalNumber(j) - jacobsthalNumber(j - 1);
        if (pIndex > this->pend.size())
            pIndex = this->pend.size();
        for (; pIndex > 0; pIndex--)
        {
            i = binarySearch(pIndex - 1, 0, this->main.size() - 1);
            if (this->main[i].back() > this->pend[pIndex - 1].back())
                this->main.insert(this->main.begin() + i, this->pend[pIndex - 1]);
            else
                this->main.insert(this->main.begin() + i + 1, this->pend[pIndex - 1]);
            this->pend.erase(this->pend.begin() + pIndex - 1);
        }
    }
    this->pend.clear();
    this->main.push_back(this->trash);
    this->trash.clear();
    if (nNumBlock > 2)
        this->reverseBlocking();
}
template <typename T>
size_t PmergeMe<T>::binarySearch(size_t j, size_t l, size_t t)
{
    size_t i = 0;
    i = (t-l) / 2 + l;
    if (this->pend[j].back() > this->main[i].back() && t != l)
        return (binarySearch(j, i + 1, t));
    else if (this->pend[j].back() < this->main[i].back() && t != l && i != l)
        return (binarySearch(j, l, i - 1));
    return (i);
}
template <typename T>
void PmergeMe<T>::start()
{
    blocking();
    reverseBlocking();
    
    // if (isSorted(this->main))
    //     std::cout << "\033[32mSORTED!!!\033[0m" << std::endl;
    // else
    //     std::cout << "\033[31mMIXED =(\033[0m" << std::endl;
}
template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &copy){
    *this = copy;
}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe<T>& copy){
    if (this == &copy)
        return (*this);
    this->nNumBlock = copy.nNumBlock;
    this->n_num = copy.n_num;
    this->main = copy.main;
    this->pend = copy.pend;
    this->trash = copy.trash;
    return (*this);
}
#endif