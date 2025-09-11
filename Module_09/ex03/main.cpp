#include"PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "./PmergeMe <numbers>\n", 1);
    Pmerge(av[1]);
}