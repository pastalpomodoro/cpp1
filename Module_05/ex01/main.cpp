#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Form form("Davide");
    Bureaucrat b(10);

    b.signForm(form);
}