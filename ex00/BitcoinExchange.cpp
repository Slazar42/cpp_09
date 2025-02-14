/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:05:38 by slazar            #+#    #+#             */
/*   Updated: 2025/02/14 01:52:47 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::string line;
	std::string date;
	float price;

	std::ifstream dataFile("./data.csv");
	if (!dataFile.is_open())
		throw std::runtime_error("Error opening file.\n");
	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		ss >> price;
		btcMap.insert(std::make_pair(date, price));
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj)
{
	if (this == &obj)
		return (*this);
	btcMap = obj.btcMap;
	return *this;
}

bool BitcoinExchange::validDate(const std::string& date)
{
    if (date.size() != 11 || date[4] != '-' || date[7] != '-')
    {
        return false;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
        {
            return false;
        }
    }

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    if (year < 2009 || year > 2023)
    {
        return false;
    }
    if (month < 1 || month > 12)
    {
        return false;
    }
    if (day < 1 || day > 31)
    {
        return false;
    }

    return true;
}

float BitcoinExchange::get_btc_value(const std::string &date)
{
	std::map<std::string, float>::iterator it = btcMap.begin();
	while (it != btcMap.end())
	{
		if (it->first == date)
			return it->second;
		if(it->first > date)
			return std::prev(it)->second;
		++it;
	}
	return -1;
}

void BitcoinExchange::readInput(std::string const &path)
{
	std::string line;
	std::ifstream dataInput(path);

	if (!dataInput.is_open())
		throw std::runtime_error("Error opening file.\n");
	std::getline(dataInput, line);
	if (line != "date | value")
		throw std::runtime_error("Invalid file format.\n");
	while (std::getline(dataInput, line))
	{
		std::string date;
		float price;
		std::stringstream ss(line);
		std::getline(ss, date, '|');
		if(line.find('|') == std::string::npos || BitcoinExchange::validDate(date) == false)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		ss >> price;
		if(price > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		if(price < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		float value = get_btc_value(date);
		if(value == -1)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		std::cout << date << " => " << price << " => " << price * value << std::endl;
	}
}

