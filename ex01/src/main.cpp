/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:27:39 by seozkan           #+#    #+#             */
/*   Updated: 2024/05/05 13:04:21 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char const *argv[])
{
    try
    {
        if (argc != 2)
            throw std::invalid_argument("Error: Bad argument count!");

        RPN rpn;
        rpn.calculate(argv);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}