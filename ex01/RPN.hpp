/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:35:39 by slazar            #+#    #+#             */
/*   Updated: 2025/02/14 02:34:07 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>

class RPN
{
public:
	RPN();
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
	~RPN();

	void readInput(std::string input);
	void calculate();
	void printResult() const;
	private:
	std::stack<std::string> _input;
	std::stack<double> _stack;
	double _result;
};
