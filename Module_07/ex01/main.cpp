#include "iter.hpp"

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6};
    iter(a, 6, multi<int>);
    for (int i = 0; i < 6; i++){
        std::cout << a[i] << "  ";
    }

    std::cout << std::endl;
    std::string s[] = {"salur", "nager", "manger", "sauter"};
    iter(s, 4, upper<std::string>);
    for (int i = 0; i < 4; i++){
        std::cout << s[i] << "  ";
    }

    std::cout << std::endl;
    float f[] = {12.0, 12.23, 5.2334, 4.4324324};
    std::cout << std::fixed;
    iter(f, 4, print<float>);
    std::cout << std::endl;
}