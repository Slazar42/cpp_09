/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:48:47 by slazar            #+#    #+#             */
/*   Updated: 2025/02/08 18:36:42 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange{
	private :
		std::map<std::string,float> btcMap;
	public :
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &obj);
		BitcoinExchange &operator=(BitcoinExchange const &obj);
		void readInput(std::string const &path);
		bool validDate(std::string const &date);
		float get_btc_value(std::string const &date);
};