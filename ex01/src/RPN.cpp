/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:45:36 by seozkan           #+#    #+#             */
/*   Updated: 2024/05/05 13:03:48 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &){}
RPN &RPN::operator=(const RPN &){return *this;}

bool RPN::isOperator(char token)
{
    return token == '+' or token == '-' or token == '*' or token == '/';
}

void RPN::calculate(char const *argv[])
{
    std::istringstream ss(argv[1]);
    std::stack<int> intStack;
    char token;
    int a, b, c;

    while (ss >> token)
    {
        if (isOperator(token))
        {
            if (intStack.size() < 2)
                throw std::runtime_error("Error: There are not enough numbers!");
            b = intStack.top();
            intStack.pop();
            a = intStack.top();
            intStack.pop();
            switch (token)
            {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                if (b == 0)
                    throw std::runtime_error("Error: Zero division!");
                c = a / b;
                break;
            }
            intStack.push(c);
        }
        else if (isdigit(token))
            intStack.push(token - '0');
        else
            throw std::invalid_argument("Error: Bad argument!");
    }

    if (intStack.size() != 1)
        throw std::runtime_error("Error: Invalid input expression");

    std::cout << intStack.top() << std::endl;
}