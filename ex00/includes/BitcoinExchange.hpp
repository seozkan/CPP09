/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:15:00 by seozkan           #+#    #+#             */
/*   Updated: 2024/05/09 12:10:07 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stdlib.h>

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &);
    BitcoinExchange &operator=(const BitcoinExchange &);
    ~BitcoinExchange();
    
    std::map<std::string, double> readData();
    std::string getLowDate();
    double findRate(std::string date, std::map<std::string, double> data);
    void checkInput(char *file, std::map<std::string, double> data);
    std::string moveDateBackOneDay(const std::string &date);
    std::string intToString(int value);
    bool ifValidDate(const std::string &date);
    bool ifValidValue(const std::string &value);
};