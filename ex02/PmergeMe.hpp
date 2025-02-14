/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:36:27 by slazar            #+#    #+#             */
/*   Updated: 2025/02/14 02:37:16 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

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
        void sortLists();
		template <typename T>
		void sortPairs(T &lst);
        template <typename T> 
        void FordJohnson(T &lst);
		template <typename T>
		double gettingTime(T &lst);
		template <typename T>
		void inserInlist(int n, T &lst);
        void printTime();
};
