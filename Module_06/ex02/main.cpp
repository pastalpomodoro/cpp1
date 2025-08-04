#include"Base.hpp"
#include"A.hpp"
#include"B.hpp"
#include"C.hpp"

Base * generate(void)
{
    int t;
    t = clock() % 3;
    // std::cout << "TypeSwitch: " << t << std::endl;
    switch(t){
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
    }
    return (NULL);
}
void identify(Base* p)
{
    if (!p)
        std::cout << "Base NULL\n";
    else if (dynamic_cast<A*>(p))
        std::cout << "It's A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "It's B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "It's C\n";
    else
        std::cout << "None\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "It's A\n";
    }
    catch(...){}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "It's B\n";
    }
    catch(...){}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "It's C\n";
    }
    catch(...){}
}

int main(void)
{
    Base *b = generate();
    Base &p = *b;
    identify(b);
    identify(p);
    delete b;
    return (1);
}