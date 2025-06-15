#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
    AForm form("Davide");
    Bureaucrat b(11);

    std::cout << form << std::endl;
    try{
        form.beSigned(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << form << std::endl;
}