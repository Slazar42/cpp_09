/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:45:00 by slazar            #+#    #+#             */
/*   Updated: 2025/02/14 02:01:36 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

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

template <typename T>
double PmergeMe::gettingTime(T &lst)
{
	std::clock_t start, end;
	start = std::clock();
	FordJohnson(lst);
	end = std::clock();
	return (double) (end - start) / (double)CLOCKS_PER_SEC;
}	

void PmergeMe::sortLists()
{
	for(size_t i = 0; i < non_sorted_vec.size(); ++i)
	{
		sorted_deque.push_back(non_sorted_vec[i]);
		sorted_vec.push_back(non_sorted_vec[i]);
	}
	deque_time = gettingTime(sorted_deque);
	vec_time = gettingTime(sorted_vec);
}
template <typename T>
void PmergeMe::sortPairs(T &lst)
{
	int tmp; 
	size_t size = lst.size();
	if (size % 2 != 0)
		size--;
	for (size_t i = 0; i < size; i += 2)
	{
		if (lst[i] > lst[i + 1])
		{
			tmp = lst[i];
			lst[i] = lst[i + 1];
			lst[i + 1] = tmp;
		}
	}
}

template <typename T>
void PmergeMe::inserInlist(int n, T &lst)
{
	typename T::iterator  high, mid, low;
	
	low = lst.begin();
	high = lst.end();
	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (*mid < n)
			low = mid + 1;
		else
			high = mid;
	}
	lst.insert(low, n);
}

template <typename T>
void PmergeMe::FordJohnson(T &lst)
{
	T pending;
	PmergeMe::sortPairs(lst);
	if (lst.size() % 2 != 0)
	{
		pending.push_back(lst.back());
		lst.pop_back();
	}
	for(int i = lst.size() - 2; i >= 0; i -= 2)
	{
        pending.push_back(*(lst.begin() + i));
        lst.erase(lst.begin() + i);
	}
	if(pending.size() > 2)
		FordJohnson(lst);
	for(size_t i = 0; i < pending.size(); i++)
		inserInlist(pending[i], lst);
}

void PmergeMe::printTime()
{
	std::cout << "Before sorting: ";
	for (size_t i = 0; i < non_sorted_vec.size(); i++)
		std::cout << non_sorted_vec[i] << " ";
	std::cout << std::endl;

	std::cout << "After sorting: ";
	for (size_t i = 0; i < sorted_vec.size(); i++)
		std::cout << sorted_vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << non_sorted_vec.size() << " elements with deque: " << std::fixed  << deque_time << " seconds" << std::endl;
	std::cout << "Time to process a range of " << non_sorted_vec.size() << " elements with vector: " << std::fixed << vec_time << " seconds" << std::endl;
}
	
