#include"BitcoinExchange.hpp"

int main(int ac, char **av){
	if (ac != 2)
	{
		std::cerr << "./btc <file>" << std::endl;
		return (1);
	}
	BitcoinExchange btc(av[1]);

	btc.finder();
}