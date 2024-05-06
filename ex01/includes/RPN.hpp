/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:45:38 by seozkan           #+#    #+#             */
/*   Updated: 2024/05/06 22:55:14 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <stack>

class Rpn
{
public:
    Rpn();
    Rpn(const Rpn &);
    Rpn &operator=(const Rpn &);
    ~Rpn();

    bool isOperator(char token);
    void calculate(char const *argv[]);
};
