#include"easyfind.hpp"

int main(void)
{
    std::vector<int>    x;
    for (int i = 0; i < 11; i++)
        x.push_back(i);
    std::string i = "salut";
    try{
        std::cout << *easyfind<std::vector<int> >(x, 10) << std::endl;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << *easyfind<std::vector<int> >(x, -1) << std::endl;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << *easyfind<std::string>(i, 10) << std::endl;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }   
}