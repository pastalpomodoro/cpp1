#include"Serializer.hpp"

int main(void)
{
    Data *data = new Data();
    data->setValue("ciao io sono martino");
    if (!data)
        std::cout << "Merde\n";
    uintptr_t t = Serializer::serialize(data);
    std::cout << t << std::endl;
    Data *data1 = Serializer::deserialize(t);
    std::cout << data1->getValue() << std::endl;
    delete data;
}