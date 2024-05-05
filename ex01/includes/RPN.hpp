/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:45:38 by seozkan           #+#    #+#             */
/*   Updated: 2024/05/05 13:02:45 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
public:
    RPN();
    RPN(const RPN &);
    RPN &operator=(const RPN &);
    ~RPN();

    bool isOperator(char token);
    void calculate(char const *argv[]);
};
