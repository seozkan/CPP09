/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:28:36 by seozkan           #+#    #+#             */
/*   Updated: 2024/05/05 12:56:55 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char *argv[])
{
    int value;
    char *end;
    for (int index = 1; index < argc; index++)
    {
        value = static_cast<int>(strtol(argv[index], &end, 10));
        if (*end || value < 0)
            throw std::invalid_argument("Invalid parameters");
        intVec.push_back(value);
        intDeque.push_back(value);
    };
};

PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other)
{
    intVec = other.intVec;
    intDeque = other.intDeque;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this == &other)
        return *this;
    intVec.clear();
    intDeque.clear();
    intVec = other.intVec;
    intDeque = other.intDeque;
    return *this;
}

void PmergeMe::printVec(std::string text)
{
    std::vector<int>::const_iterator it;

    std::cout << text;
    for (it = intVec.begin(); it != intVec.end(); it++)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

void PmergeMe::exec()
{
    printVec("Before: ");
    timespec startVec, endVec, startDeq, endDeq;
    clock_gettime(CLOCK_MONOTONIC, &startVec);
    MergeInsertionSort(intVec, 0, intVec.size() - 1);
    clock_gettime(CLOCK_MONOTONIC, &endVec);
    clock_gettime(CLOCK_MONOTONIC, &startDeq);
    MergeInsertionSort(intDeque, 0, intDeque.size() - 1);
    clock_gettime(CLOCK_MONOTONIC, &endDeq);
    printVec("After: ");
    double timeVec = (endVec.tv_sec - startVec.tv_sec) * 1e3 + (endVec.tv_nsec - startVec.tv_nsec) / 1e6;
    double timeDeq = (endDeq.tv_sec - startDeq.tv_sec) * 1e3 + (endDeq.tv_nsec - startDeq.tv_nsec) / 1e6;
    std::cout << "Time to process a range of " << intVec.size() << " elements with std::vec container: " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << intDeque.size() << " elements with std::deque container: " << timeDeq << " us" << std::endl;
}
