#include"PmergeMe.hpp"

size_t jacobsthalNumber(size_t n)
{
    size_t j = 2;
    for (size_t i = 1; i < n; i++){
        j *= 2;
    }
    if (n % 2 == 0)
        j -= 1;
    else
        j += 1;
    j /= 3;
    return j;
}

int main(int ac, char **av)
{
    if (ac <= 2)
        return (std::cout << "./PmergeMeMe <numbers>\n", 1);    
    try
    {
        PmergeMe<std::vector<size_t> > v(av);
        size_t i = 1;
        std::cout << "Before: ";
        for (; av[i+1]; i++){
            std::cout << av[i] << " ";
        }
        std::cout << av[i] << std::endl;
        clock_t time = clock();
        v.start();
        std::cout << "After: ";
        std::vector<std::vector<size_t> >  temp = v.getMain();
        for (std::vector<std::vector<size_t> >::iterator it = temp.begin(); it != temp.end(); ++it){
            for (std::vector<size_t>::iterator et = it->begin(); et != it->end(); ++et){
                std::cout << *et << " ";
            }
        }
        std::cout << std::endl;
        double duration = (double)(clock() - time) / CLOCKS_PER_SEC * 1e6;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << duration << " us" << std::endl;

        PmergeMe<std::deque<size_t> > d(av);
        time = clock();
        d.start();
        duration = (double)(clock() - time) / CLOCKS_PER_SEC * 1e6;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << duration << " us" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}