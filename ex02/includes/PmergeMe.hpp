/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:28:33 by seozkan           #+#    #+#             */
/*   Updated: 2024/05/05 12:53:37 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
public:
    PmergeMe(int argc, char *argv[]);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    std::vector<int> intVec;
    std::deque<int> intDeque;

    void printVec(std::string text);
    void exec();

    template <typename T>
    static void insertionSort(T &container, int start, int end)
    {
        for (int i = start + 1; i <= end; ++i)
        {
            int key = container[i];
            int j = i - 1;

            while (j >= start && container[j] > key)
            {
                container[j + 1] = container[j];
                --j;
            }
            container[j + 1] = key;
        }
    }

    template <typename T>
    static void merge(T &container, int start, int mid, int end)
    {
        T temp(end - start + 1);
        int i = start, j = mid + 1, k = 0;

        while (i <= mid && j <= end)
        {
            if (container[i] < container[j])
                temp[k++] = container[i++];
            else
                temp[k++] = container[j++];
        }

        while (i <= mid)
            temp[k++] = container[i++];

        while (j <= end)
            temp[k++] = container[j++];

        for (int i = 0; i < k; ++i)
            container[start + i] = temp[i];
    }

    template <typename T>
    void MergeInsertionSort(T &container, int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            if (end - start + 1 <= 10)
            {
                insertionSort(container, start, end);
            }
            else
            {
                MergeInsertionSort(container, start, mid);
                MergeInsertionSort(container, mid + 1, end);
                merge(container, start, mid, end);
            }
        }
    }
};

#endif