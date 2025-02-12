/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:45:00 by slazar            #+#    #+#             */
/*   Updated: 2025/02/12 02:45:01 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : deque_time(0), vec_time(0) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if (this == &obj)
		return (*this);
	sorted_deque = obj.sorted_deque;
	sorted_vec = obj.sorted_vec;
	non_sorted_vec = obj.non_sorted_vec;
	deque_time = obj.deque_time;
	vec_time = obj.vec_time;
	return *this;
}

void PmergeMe::storData(int ac, char **av)
{
    std::string args;
    std::stringstream ss;
    int i = 1;

    while(i < ac)
    {
        ss << av[i];
        while(ss >> args)
        {
            if (args.empty())
            {
                i++;
                continue;
            }
            for (size_t j = 0; j < args.length(); j++)
            {
                if(args.at(j) == '-')
					throw std::runtime_error("Error: negative number\n");
                else if (args.at(j) == '+' && std::isdigit(args.at(j + 1)))
                    continue;
                else if (!std::isdigit(args.at(j)))
					throw std::runtime_error("Error: invalid input\n");
            }
			non_sorted_vec.push_back(std::stoi(args));
        }
        ss.clear();
        i++;
    }

}

void PmergeMe::sortAnyList()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;

	for(size_t i = 0; i < non_sorted_vec.size(); ++i)
	{
		sorted_deque.push_back(non_sorted_vec[i]);
		sorted_vec.push_back(non_sorted_vec[i]);
	}
	start = std::chrono::system_clock::now();
	Ford_Johnson(sorted_deque);
	end = std::chrono::system_clock::now();
	deque_time = std::chrono::duration<double>(end - start).count();

	start = std::chrono::system_clock::now();
	Ford_Johnson(sorted_vec);
	end = std::chrono::system_clock::now();
	vec_time = std::chrono::duration<double>(end - start).count();
}

template <typename T>
void PmergeMe::Ford_Johnson(T &lst)
{
	(void)lst;

}