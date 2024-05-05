/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:28:40 by seozkan           #+#    #+#             */
/*   Updated: 2024/05/05 13:06:00 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int argc, char *argv[])
{
	try
	{
		if (argc < 3)
			throw std::invalid_argument("Not enough arguments in parameters!");

		PmergeMe pmergeme(argc, argv);
		pmergeme.exec();
	}
	catch (const std::exception &e)
	{
		std::cout << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
		return 1;
	}
	return 0;
}