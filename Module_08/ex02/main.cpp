#include"MutantStack.hpp"

int main(void){
    MutantStack<int> a;
    a.push(12);
    a.push(14);
    MutantStack<int>::iterator b = a.begin();
    while (b != a.end())
    {
        std::cout << *b << std::endl;
        b++;
    }
}