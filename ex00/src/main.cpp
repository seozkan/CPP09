/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:14:58 by seozkan           #+#    #+#             */
/*   Updated: 2024/05/05 13:05:51 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		BitcoinExchange exchange;

		if (argc != 2)
			throw std::runtime_error("Error: Could not open file");
		std::map<std::string, double> data = exchange.readData();
		exchange.checkInput(argv[1], data);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}