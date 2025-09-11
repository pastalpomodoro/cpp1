#include<iostream>
#include<deque>
#include<sstream>

int main(int ac, char **av)
{
    if (ac != 1)
        return 1;
    // std::string temp(av[1]);
    // std::istringstream ill(temp);
    // std::string token;
    // while (ill >> token)
    //     std::cout << token << std::endl;
    std::string     temp = "123d";

    std::cout << atoi(temp.c_str()) << std::endl;
}