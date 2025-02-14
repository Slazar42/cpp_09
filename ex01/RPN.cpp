/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:36:45 by slazar            #+#    #+#             */
/*   Updated: 2025/02/14 02:14:32 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _result(0) {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
	{
		_input = copy._input;
		_stack = copy._stack;
		_result = copy._result;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::readInput(std::string input)
{
	std::istringstream iss(input);
	std::string token;
	while (iss >> token)
		_input.push(token);
}

void RPN::calculate()
{
	std::stack<std::string> reversedInput; 
	std::stack<double> tempStack;
	double num;

	while (!_input.empty())
	{
		reversedInput.push(_input.top());
		_input.pop();
	}

	while (!reversedInput.empty())
	{
		std::string inp = reversedInput.top();
		reversedInput.pop();
		if (inp == "+" || inp == "-" || inp == "*" || inp == "/" || inp == "%")
		{
			if (tempStack.size() < 2)
				throw std::invalid_argument("Error: not enough operands.");

			double a = tempStack.top();
			tempStack.pop();
			double b = tempStack.top();
			tempStack.pop();

			if (inp == "+")
				tempStack.push(b + a);
			else if (inp == "-")
				tempStack.push(b - a);
			else if (inp == "*")
				tempStack.push(b * a);
			else if (inp == "/")
			{
				if (a == 0)
					throw std::invalid_argument("Error: division by zero.");
				tempStack.push(b / a);
			}
			else if (inp == "%")
				tempStack.push(fmod(b, a));
		}
		else
		{
			std::istringstream iss(inp);
			if (!(iss >> num))
				throw std::invalid_argument("Error: invalid input.");
			tempStack.push(num);
		}
	}

	if (tempStack.size() != 1)
		throw std::invalid_argument("Error: too many operands.");

	_result = tempStack.top();
}

void RPN::printResult() const
{
	std::cout << _result << std::endl;
}