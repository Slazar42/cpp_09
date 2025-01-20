/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:05:38 by slazar            #+#    #+#             */
/*   Updated: 2025/01/20 20:56:27 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	std::string line;
	std::string date;
	float price;

	std::ifstream dataFile("./data.csv");
	if (!dataFile.is_open())
		throw std::runtime_error("Error opening file.\n");
	std::getline(dataFile,line);
	while(std::getline(dataFile,line))
	{
		std::stringstream ss(line);
		std::getline(ss,date,',');
		ss >> price;
		btcMap.insert(std::make_pair(date, price)); 
	}
}

BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj){
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj){
	if(this == &obj)
		return(*this);
	btcMap = obj.btcMap;
	return *this ;
}
void BitcoinExchange::readInput(std::string const &path){
	std::string line;
	std::ifstream dataInput(path);
	
	if (!dataInput.is_open())
		throw std::runtime_error("Error opening file.\n");
	std::getline(dataInput,line);
	std::string line;
    std::getline(b.input, line);//skip first line
    if(std::strcmp(line.c_str(), "date | value") != 0)
        std::cerr << RED <<"bad Header" << RESET << std::endl;