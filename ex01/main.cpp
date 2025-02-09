/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:37:30 by slazar            #+#    #+#             */
/*   Updated: 2025/02/09 22:37:40 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::invalid_argument("Error: could not open file.");
		RPN rpn;
		rpn.readInput(av[1]);
		rpn.calculate();
		rpn.printResult();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}