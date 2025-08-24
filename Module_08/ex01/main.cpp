#include"Span.hpp"

int main(void)
{
    Span s(10);
    std::vector<int> a;
    try{
        for (int i = 0; i < 10;i++)
            a.push_back(i);
        s.addMultiNumber(a, a.size());
        std::cout << s.longestSpan() << std::endl;
        std::cout << s.shortestSpan() << std::endl;
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}