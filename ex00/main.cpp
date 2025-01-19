/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:59:19 by slazar            #+#    #+#             */
/*   Updated: 2025/01/19 21:29:36 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

int main(int ac,char **av)
{
	if (ac != 2)
	{
		std::cerr<< "Error: could not open file.\n";
		return(EXIT_FAILURE);
	}
	BitcoinExchange btc;
	btc.readInput(av[1]);
}