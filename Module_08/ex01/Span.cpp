#include"Span.hpp"

Span::Span(void) : _N(0){}
Span::Span(const Span &copy){
    *this = copy;
}
Span::Span(unsigned int n) : _N(n){}
Span::~Span(void){}

Span&   Span::operator=(const Span &copy){
    if (this == &copy)
        return (*this);
    this->_span.clear();
    this->_span.insert(this->_span.end(), copy._span.begin(), copy._span.end());
    this->_span = copy._span;
    this->_N = copy._N;
    return (*this);
}

void    Span::addNumber(const int n){
    if (this->_span.size() >= this->_N)
        throw SpanOverflowException();
    this->_span.push_back(n);
}

int     Span::shortestSpan()
{
    if (this->_span.size() <= 1)
        throw SpanNotFound();
    std::vector<int>::iterator it = std::min_element(this->_span.begin(), this->_span.end());
    return (*it);
}
int     Span::longestSpan()
{
    if (this->_span.size() <= 1)
        throw SpanNotFound();

    std::vector<int>::iterator it = std::max_element(this->_span.begin(), this->_span.end());
    return (*it);
}

void    Span::addMultiNumber(std::vector<int> n, size_t size)
{
    if (this->_span.size() + size > this->_N)
        throw SpanOverflowException();
    this->_span.insert(this->_span.end(), n.begin(), n.end());
}