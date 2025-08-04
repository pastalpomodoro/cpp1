#include<iostream>
int main(void){
    std::string s = "1232.0";
    char *endptr = NULL;
    float f = 12.0f;

    long int x = std::strtof(s.c_str(), &endptr);
    if (endptr[0] == '\0'){
        std::cout << x << std::endl;
        std::cout << std::isdigit(s[0]) << std::endl;
    }
}