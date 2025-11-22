#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *av) : input(av), date(""), num(0)
{
    std::ifstream       file("data.csv");
    std::string         temp = "";
    double              num;
    if (!file.is_open())
        throw (std::runtime_error("Error opening the csv file"));
    for (int i = 0; std::getline(file, temp); i++){
        if (i != 0)
        {    
            std::string         temp1 = "";
            std::istringstream  ill(temp);
            std::getline(ill, temp, ',');
            std::getline(ill, temp1, ',');
            std::istringstream  numTemp(temp1);
            numTemp >> num;
            this->btc[temp] = num;
        }
    }
    file.close();
    // for (std::map<std::string, double>::iterator it = this->btc.begin(); it != this->btc.end(); it++){
        // std::cout << it->first << " " << it->second << std::endl;
    // }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}
BitcoinExchange::~BitcoinExchange(void){;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy){
    if (this == &copy)
        return (*this);
    this->btc = copy.btc;
    this->date = copy.date;
    this->num = copy.num;
    this->inYear = copy.inYear;
    this->inMonth = copy.inMonth;
    this->inDay = copy.inDay;
    return (*this);
}

bool    BitcoinExchange::checkDate(){
    if (this->date[this->date.length() - 1] != ' ')
        return (false);
    this->date = this->date.substr(0, this->date.length() - 1);
    std::istringstream  ill(this->date);
    std::string         temp = "";

    for (int i = 0; std::getline(ill, temp, '-'); i++){
        if (i > 2)
            return (false);
        for (int j = 0; temp[j]; j++){
            if (!isdigit(temp[j]))
                return (false);
        }
        std::istringstream  numTemp(temp);
        int                 num;
        numTemp >> num;
        if ((i == 1 && num > 12) || (i == 2 && num > 31))
            return (false);
    }
    return (true);
}

bool    BitcoinExchange::checkNum(std::string temp1, std::string line){
    
    if (temp1.length() <= 1 || temp1[0] != ' ')
        return (std::cout << "error: bad input => " << line << std::endl, false);
    if (temp1[1] == '-')
        return (std::cout << "error: not a positive number.\n", false);
    std::istringstream  numTemp(&temp1[1]);
    numTemp >> this->num;
    // std::cout << "NUM: " << num << std::endl;
    if (this->num > 1000)
        return (std::cout << "Error: too large a number.\n", false);
    // std::cout << this->date << " " << this->num << std::endl;
    return (true);
}

void    BitcoinExchange::setDates(){
    std::string temp1 = "";
    std::istringstream  inDate(this->date);
    
    for (int i = 0; i < 3; i++){
        std::getline(inDate, temp1, '-');
        std::istringstream  ill(temp1);
        if (i == 0)
            ill >> this->inYear;
        else if (i == 1)
            ill >> this->inMonth;
        else
            ill >> this->inDay;
    }
}


bool    BitcoinExchange::isBissextile(){
    //verificare che il mese sia tra 01 et 12
    //verificare per gli bissextiles
    //verificare per i mesi che ahnno meno giorni che il giorno non sia troppo grande
    // std::cout << "MONTH: " << this->inMonth << " DAY: " << this->inDay << " YEAR: " << this->inYear << std::endl;
    if (this->inYear % 4 == 0 && this->inYear % 100 != 0 && this->inMonth == 2 && this->inDay > 29)
        return false;
    if ((this->inMonth == 1 || 
            this->inMonth == 3 || this->inMonth == 5 || 
            this->inMonth == 7 || this->inMonth == 8 || 
            this->inMonth == 10 || this->inMonth == 12)
            && this->inDay > 31)
        return false;
    if ((this->inMonth == 4 || 
            this->inMonth == 6 || 
            this->inMonth == 9 ||
            this->inMonth == 11)
            && this->inDay > 30)
        return false;
    if (this->inMonth == 2 && this->inDay > 28)
        return false;
    if (this->inMonth <= 0 || this->inDay > 12)
        return false;
    return true;
}

bool    BitcoinExchange::isSmallerDate(std::string date)
{
	int btcYear;
	int btcMonth;
	int btcDay;

    if (date == "")
        return (true);	
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
	if (this->inYear > btcYear)
		return (false);
	if (this->inMonth > btcMonth && this->inYear == btcYear)
		return (false);
	if (this->inDay > btcDay && this->inYear == btcYear && this->inMonth == btcMonth)
		return (false);
	return (true);
}

bool    BitcoinExchange::findDate(){
    this->setDates();
    if (!isBissextile())
        return (false);
    // std::cout << "YEAR: "  << this->inYear << " MOUNTH: " << this->inMonth << " DAY: " << this->inDay << std::endl;
    std::string temp;

    if (this->btc.find(this->date) != this->btc.end())
        return (std::cout << this->date << " => " << this->num << " = " << this->btc[this->date] * this->num << std::endl, true);
    std::map<std::string, double>::iterator it = this->btc.begin();
    while (it != this->btc.end()){
        if (isSmallerDate(it->first) && !isSmallerDate(temp)){
            std::cout << this->date << " => " << this->num << " = " << this->num * this->btc[it->first] << std::endl;
            return (true);
        }
        temp = it->first;
        ++it;
    }
    return (false);
}
void    BitcoinExchange::finder()
{
    std::string line;

    std::getline(this->input, line);
    while (std::getline(this->input, line))
    {
        if (line == "")
            continue;
        std::istringstream  ill(line);
        std::string         temp1;
        std::getline(ill, this->date, '|');
        if (!this->checkDate()){
            std::cout << "error: bad input => " << line << std::endl;
            continue;
        }
        std::getline(ill, temp1, '|');
        if (!this->checkNum(temp1, line))
            continue;
        if (!this->findDate())
            std::cout << "error: bad input => " << line << std::endl;
    }
}