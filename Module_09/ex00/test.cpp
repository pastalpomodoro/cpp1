#include<iostream>
#include<fstream>
#include<sstream>

int                             inYear = 2022;
int                             inMonth = 3;
int                             inDay = 1;
bool isSmallerDate(std::string date)
{
	int btcYear;
	int btcMonth;
	int btcDay;
	std::string temp;
	std::istringstream ill(date);
	std::getline(ill, temp, '-');
	std::istringstream t(temp);
	t >> btcYear;
	std::getline(ill, temp, '-');
	std::istringstream t1(temp);
	t1 >> btcMonth;
	std::getline(ill, temp, '-');
	std::istringstream t2(temp);
	t2 >> btcDay;
	std::cout << btcYear << " " << btcMonth << " " << btcDay << std::endl;
	if (inYear > btcYear)
		return (false);
	if (inMonth > btcMonth)
		return (false);
	if (inDay > btcDay);
		return (false);
	return (true);
}
int main(void){
	std::string s = "2023-02-01";
	isSmallerDate(s);
}