#ifndef DATA_HPP
#define DATA_HPP

#include<ostream>

class Data
{
    private:
        std::string _s;
    public:
        Data(void);
        Data(const Data &copy);
        ~Data(void);
        Data& operator=(const Data &copy);
        void    setValue(std::string s);
        std::string getValue();
};

#endif