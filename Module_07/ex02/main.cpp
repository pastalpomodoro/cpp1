#include "Array.hpp"

int main()
{
    std::string *a = new std::string[4];
    a[0] = "salut";
    a[1] = "ciao";
    a[2] = "hello";
    a[3] = "gutentagen";

    Array<std::string> b(a, 4);
    b.showData();
    std::cout << std::endl;
    std::string c[4];
    c[0] = "caca";
    c[1] = "pipi";
    c[2] = "";
    c[3] = "thomas";
    b.setData(c);
    b.showData();
    delete[] a;
}