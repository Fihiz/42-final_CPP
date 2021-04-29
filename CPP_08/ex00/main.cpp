/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:38:26 by salome            #+#    #+#             */
/*   Updated: 2021/04/21 20:42:48 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	displayInt( int i )
{
	std::cout << T_GYB "List content: ";
	std::cout << T_BB << i << T_N << std::endl;
	return ;
}

void	testingEasyfindForList( std::list<int> lst, std::list<int>::const_iterator it, int nToFind )
{
	try
	{
		it = easyfind(lst, nToFind);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testingEasyfindForVector( std::vector<int> vct, std::vector<int>::const_iterator it1, int nToFind )
{
	try
	{
		it1 = easyfind(vct, nToFind);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int		main( void )
{
	std::list<int> lst;						// List template container
	std::list<int>::const_iterator it;		// List template const iterator

	int numbers[5] = { 10, 20, 3, 17, 20 };
	for (int i = 0; i < 5; i++)
		lst.push_back(numbers[i]);
		
	std::cout << T_GN "\nList filling check" T_N << std::endl;
	for_each(lst.begin(), lst.end(), displayInt);

	std::cout << T_GN "\nCalling easyfind" T_N << std::endl;
	try
	{
		// Calling easyfind
		testingEasyfindForList(lst, it, 20);
		testingEasyfindForList(lst, it, -20);
		testingEasyfindForList(lst, it, 21);
		testingEasyfindForList(lst, it, 3);
		testingEasyfindForList(lst, it, 10);
		testingEasyfindForList(lst, it, -1);
		testingEasyfindForList(lst, it, 58972);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	
	std::vector<int> vct;					// Vector template container
	std::vector<int>::const_iterator it1;	// Vector template const iterator

	std::cout << T_GN "\nVector filling check" T_N << std::endl;
	for (int i = 0; i < 4; i++)
		vct.push_back(i);
	for_each(vct.begin(), vct.end(), displayInt);

	std::cout << T_GN "\nCalling easyfind" T_N << std::endl;
	try
	{
		// Calling easyfind
		testingEasyfindForVector(vct, it1, 3);
		testingEasyfindForVector(vct, it1, 0);
		testingEasyfindForVector(vct, it1, 1);
		testingEasyfindForVector(vct, it1, 2);
		testingEasyfindForVector(vct, it1, -158);
		testingEasyfindForVector(vct, it1, 4);
		testingEasyfindForVector(vct, it1, 4 - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;


	std::vector<int> vct1;					// Vector template container
	std::vector<int>::const_iterator it2;	// Vector template const iterator

	std::cout << T_GN "\nVector filling check" T_N << std::endl;
	for (int i = 0; i < 6; i++)
		vct1.push_back(158 * i);
	for_each(vct1.begin(), vct1.end(), displayInt);

	std::cout << T_GN "\nCalling easyfind" T_N << std::endl;
	try
	{
		// Calling easyfind
		testingEasyfindForVector(vct1, it2, 1048);
		testingEasyfindForVector(vct1, it2, 0);
		testingEasyfindForVector(vct1, it2, 1520584);
		testingEasyfindForVector(vct1, it2, 316);
		testingEasyfindForVector(vct1, it2, 790);
		testingEasyfindForVector(vct1, it2, 474);
		testingEasyfindForVector(vct1, it2, 640 - 8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	return (0);
}

// Testing: clang++ -Wall -Wextra -Werror main.cpp