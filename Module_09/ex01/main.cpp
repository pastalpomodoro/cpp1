#include"RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    RPN R;

    try{
        R.calculator(av[1]);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}