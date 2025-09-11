#include"RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    RPN R(av[1]);

    R.calculator();
}