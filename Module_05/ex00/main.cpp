#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "\n";
    Bureaucrat b("Roger", 150);
    Bureaucrat c(b);
    std::cout << b.getGrade() << std::endl;
    std::cout << c.getGrade() << std::endl;
    try
    {
        c.incrementGrade(23);
        b.incrementGrade(1);
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        b.decrementGrade(3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}