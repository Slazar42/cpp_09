/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:05:38 by slazar            #+#    #+#             */
/*   Updated: 2025/01/19 21:46:24 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	std::string line;
	std::string date;
	float price;
	bool scipTheFirstLine = true;

	std::ifstream dataFile("./data.csv");
	if (!dataFile.is_open())
		std::cerr <<  "Error opening file.\n";
	while(std::getline(dataFile,line))
	{
		if (scipTheFirstLine){	
			scipTheFirstLine = false;
			continue;
		}
		std::stringstream ss(line);
		if(std::getline(ss,date,',') && ss >> price)
			btcMap.insert(std::make_pair(date, price)); 
		else{
			std::cerr << "Error in parssing " << std::endl;
			continue;
		}
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
void BitcoinExchange::readInput(std::string path){
	(void)path;
	for(std::map<std::string,float>::iterator it = btcMap.begin();it != btcMap.end(); it++){
		std::cout << it->first << " price is " << it->second<< std::endl;
	}
}