#ifndef SPAN_HPP
#define SPAN_HPP

#include<iostream>
#include<algorithm>
class Span
{
    private:
        unsigned int        _N;
        std::vector<int>    _span;
    public:
        Span(void);
        Span(unsigned int n);
        Span(const Span &copy);
        ~Span(void);
        Span &operator=(const Span &copy);

        void    addNumber(const int n);
        int     shortestSpan();
        int     longestSpan();
        void    addMultiNumber(std::vector<int> n, size_t size);
    class SpanOverflowException : public std::exception
    {
        virtual const char *what() const throw(){
            return ("Span Over Flow!!!");
        }
    };
    class SpanNotFound : public std::exception
    {
        virtual const char *what() const throw(){
            return ("No Span Found!!!");
        }
    };
};

#endif