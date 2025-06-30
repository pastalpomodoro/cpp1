#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Form form("Davide");
    Bureaucrat b(10);

    std::cout << b << std::endl;
    b.signForm(form);
}