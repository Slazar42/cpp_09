/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:13:07 by slazar            #+#    #+#             */
/*   Updated: 2025/02/12 02:40:54 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac < 2)
			throw std::runtime_error("Usage: ./pmergeMe [list of positive integers]\n");
		PmergeMe pmergeMe;
		pmergeMe.storData(ac, av);
		pmergeMe.sortAnyList();
		// pmergeMe.printTime();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}