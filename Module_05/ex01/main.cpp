#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "\n";
    Bureaucrat b;
    std::cout << b.getGrade() << std::endl;
    b.decrementGrade(1);
    std::cout << b.getGrade() << std::endl;
    try
    {
        b.incrementGrade(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}