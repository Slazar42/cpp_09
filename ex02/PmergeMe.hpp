/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:36:27 by slazar            #+#    #+#             */
/*   Updated: 2025/02/12 02:42:18 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include<sstream>
#include <chrono>

class PmergeMe
{
    private:
        std::deque<int> sorted_deque;
        std::vector<int> sorted_vec;
        std::vector<int> non_sorted_vec;
        double deque_time;
        double vec_time;
    public:
        PmergeMe();
        PmergeMe &operator=(const PmergeMe &obj);
        PmergeMe(const PmergeMe &obj);
        ~PmergeMe();
        void storData(int ac, char **av);
        void sortAnyList();
        template <typename T> 
        void Ford_Johnson(T &lst);
        // void printTime();
};

