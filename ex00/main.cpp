/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:59:19 by slazar            #+#    #+#             */
/*   Updated: 2025/02/08 18:40:45 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

int main(int ac,char **av)
{
	try
	{
		if (ac != 2)
			throw std::invalid_argument("Error: could not open file.");
		BitcoinExchange btc;
		btc.readInput(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}