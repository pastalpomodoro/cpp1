#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Form form("Lorenzo", 30);
    Form form2("Andrea", 12);
    Bureaucrat b("davide", 10);
    Bureaucrat c("federico", 31);

    std::cout << form << std::endl;
    std::cout << form2 << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    b.signForm(form);
    c.signForm(form2);
    std::cout << form << std::endl;
    std::cout << form2 << std::endl;
    Form form3(form);
    std::cout << form3 << std::endl;
}