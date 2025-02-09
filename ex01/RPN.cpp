/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:36:45 by slazar            #+#    #+#             */
/*   Updated: 2025/02/09 23:29:35 by slazar           ###   ########.fr       */
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
		_input.push_back(token);
}

void RPN::calculate()
{
	for (size_t i = 0; i < _input.size(); i++)
	{
		if (_input[i] == "+" || _input[i] == "-" || _input[i] == "*" || _input[i] == "/" || _input[i] == "%")
		{
			if (_stack.size() < 2)
				throw std::invalid_argument("Error: not enough operands.");
			double a = _stack.top();
			_stack.pop();
			double b = _stack.top();
			_stack.pop();
			if (_input[i] == "+")
				_stack.push(b + a);
			else if (_input[i] == "-")
				_stack.push(b - a);
			else if (_input[i] == "*")
				_stack.push(b * a);
			else if (_input[i] == "/")
				_stack.push(b / a);
			else if (_input[i] == "%")
				_stack.push(fmod(b, a));
		}
		else
		{
			std::istringstream iss(_input[i]);
			double num;
			if (!(iss >> num))
				throw std::invalid_argument("Error: invalid input.");
			_stack.push(num);
		}
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("Error: too many operands.");
	_result = _stack.top();
}

void RPN::printResult() const
{
	std::cout << _result << std::endl;
}

