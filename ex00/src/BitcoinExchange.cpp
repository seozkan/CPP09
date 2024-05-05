#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &){}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &){return *this;}

std::map<std::string, double> BitcoinExchange::readData()
{
    std::map<std::string, double> csv;
    std::ifstream file("data.csv");
    if (!file)
        throw std::runtime_error("Error: Data.csv file not found!");
    std::string line;
    // Skip first line
    std::getline(file, line);
    // Read data from file and insert into map
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, rate;
        std::getline(ss, date, ',');
        std::getline(ss, rate, ',');
        csv[date] = std::atof(rate.c_str());
    }
    return csv;
}

void BitcoinExchange::checkInput(char *file, std::map<std::string, double> data) {
    std::string firstLine;
    std::ifstream inputFile(file);
    std::string line;

    if (!inputFile) {
        throw std::runtime_error("Error: Failed to open file.");
    }

    std::getline(inputFile, firstLine);
    if (firstLine != "date | value") {
        throw std::runtime_error("Error: First line of file is not 'date | value'.");
    }

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string value;
        char separator;
        if (!(iss >> date >> separator >> value) || separator != '|' || !ifValidDate(date) || !ifValidValue(value)) {
            std::cout << ("Error: bad input => " + date) << std::endl;
        } else if (strtod(value.c_str(), NULL) < 0) {
            std::cout << ("Error: not a positive number.") << std::endl;
        } else if (strtod(value.c_str(), NULL) > 1000) {
            std::cout << ("Error: too large a number.") << std::endl;
        } else {
            double mult = strtod(value.c_str(), NULL) * findRate(date, data);
            std::cout << date << " => " << value << " = " << mult << std::endl;
        }
    }
    inputFile.close();
}

double BitcoinExchange::findRate(std::string date, std::map<std::string, double> data)
{
    std::map<std::string, double>::iterator it = data.find(date);
    if (it != data.end())
        return it->second;
    if (date == "not valid date")
        return 0;
    return findRate(moveDateBackOneDay(date), data);
}

std::string BitcoinExchange::intToString(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

std::string BitcoinExchange::moveDateBackOneDay(const std::string &date)
{
    // Gelen string tarih bilgisini parçalara ayırmak için stringstream kullanalım
    std::istringstream ss(date);
    std::string yearStr, monthStr, dayStr;
    std::getline(ss, yearStr, '-');
    std::getline(ss, monthStr, '-');
    std::getline(ss, dayStr, '-');

    // Parçalanan tarih bilgisini integer değerlere dönüştürelim
    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    // 1 gün öncesini hesaplayalım
    if (day > 1)
        day--;
    else
    {
        if (month == 1)
        {
            month = 12;
            year--;
        }
        else
            month--;
        int dayCount;
        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            dayCount = 30;
        }
        else if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                dayCount = 29;
            else
                dayCount = 28;
        }
        else
            dayCount = 31;
        day = dayCount;
    }

    std::string newDate = intToString(year) + "-" +
                          (month < 10 ? "0" : "") + intToString(month) + "-" +
                          (day < 10 ? "0" : "") + intToString(day);

    return newDate;
}

bool BitcoinExchange::ifValidDate(const std::string &date)
{
    // Check the length of the input string
    if (date.length() != 10)
        return false;

    // Define necessary variables
    int year, month, day;
    char separator;

    // Parse the date string
    std::istringstream ss(date);
    ss >> year >> separator >> month >> separator >> day;

    // Check for parsing failures and validity of components
    if (ss.fail() || separator != '-' || year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    // Check for valid day of the month considering leap years
    bool leap_year = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    if ((month == 2 && (leap_year ? day > 29 : day > 28)) ||
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
    {
        return false;
    }

    // The input string is a valid date
    return true;
}

bool BitcoinExchange::ifValidValue(const std::string &value)
{
    // Check that the input string has the correct length
    std::istringstream iss(value);
    float floatValue;
    iss >> floatValue;

    if (iss.fail() || !iss.eof())
    {
        // std::cout << "Invalid value" << std::endl;
        return false;
    }
    else
    {
        return true;
    }
}


void BitcoinExchange::printMap(const std::map<std::string, double> &map)
{
    std::map<std::string, double>::const_iterator it;
    for (it = map.begin(); it != map.end(); ++it)
        std::cout << it->first << "=" << it->second << " ";
    std::cout << std::endl;
}