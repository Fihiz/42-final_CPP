/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:01:58 by salome            #+#    #+#             */
/*   Updated: 2021/04/21 21:00:02 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../span.hpp"

void	testingAdd( Span &src, int val )
{
	try
	{
		src.addNumber(val);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	testingAddRangeNumber( Span &src, int start, int end )
{
	try
	{
		src.addNumber(start, end);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testingLongest( Span &src )
{
	try
	{
		std::cout << src.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	testingShortest( Span &src )
{
	try
	{
		std::cout << src.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int		main( void )
{

	std::cout << T_GN "\nTesting" T_N << std::endl;
	try
	{
		Span sp = Span(5);

		// Pushing datas
		sp.addNumber(11);
		sp.addNumber(-17);
		sp.addNumber(9);
		sp.addNumber(1);
		sp.addNumber(123456789);
		
		// Filling check
		sp.displayTab();
		std::cout << std::endl;

		// Testing copy
		Span sp1(sp);
		sp1.displayTab();
		std::cout << std::endl;

		// Testing longest span
		testingLongest(sp); // 123456789 - (-17) = 123456806
		testingShortest(sp);
		std::cout << std::endl;

		// Testing both full tab
		testingAdd(sp, 0);
		testingAdd(sp1, 18);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;


	std::cout << T_GN "\nTesting" T_N << std::endl;
	try
	{
		Span sp1 = Span(4);

		// Testing empty case
		testingShortest(sp1);
		// Testing not filled enough case
		testingAdd(sp1, 599);
		testingLongest(sp1);
		std::cout << std::endl;
		
		// New entry
		testingAdd(sp1, 598);
		sp1.displayTab();

		// Testing equal spans for shortest and longest
		testingLongest(sp1);
		testingShortest(sp1);
		std::cout << std::endl;
		
		// New entries
		testingAdd(sp1, 1056 * 2);
		testingAdd(sp1, 1);
		sp1.displayTab();
		std::cout << std::endl;

		// Testing span after adding values
		testingLongest(sp1);
		testingShortest(sp1);
		
		// Testing already full
		testingAdd(sp1, 33);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << T_GN "\nTesting" T_N << std::endl;
	try
	{
		Span sp2 = Span(0);
		
		// Testing a null tab
		testingAdd(sp2, 1056);
		testingAdd(sp2, -1056);
		testingAdd(sp2, 10);
		testingAdd(sp2, 56);
		testingAdd(sp2, 56);
		sp2.displayTab();
		std::cout << std::endl;

		// Testing not filled enough
		testingLongest(sp2);
		testingShortest(sp2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;


	std::cout << T_GN "\nTesting" T_N << std::endl;
	try
	{
		Span sp3 = Span(200);

		// Testing a bigger tab
		for (unsigned int i = 0; i < sp3.getStorage(); i++)
			testingAdd(sp3, i * 2);
		//sp3.displayTab();
		//std::cout << std::endl;

		testingLongest(sp3);
		testingShortest(sp3);
		testingAdd(sp3, 20 * 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;


	try
	{
		Span sp4 = Span(10);

		// Testing add numbers passing a way of iterators
		testingAddRangeNumber(sp4, 0, sp4.getStorage() + 1);
		testingAddRangeNumber(sp4, 0,  sp4.getStorage());
		sp4.displayTab();
		testingLongest(sp4);
		testingShortest(sp4);
		testingAdd(sp4, 10002);
		testingAdd(sp4, 10002);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		Span sp4 = Span(10000);

		//sp4.displayTab();
		testingAddRangeNumber(sp4, 0, 10001);
		testingAddRangeNumber(sp4, 0, 10000);
		testingLongest(sp4);
		testingShortest(sp4);
		testingAdd(sp4, 10002);
		testingAdd(sp4, 10002);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	return (0);
}

// Testing: clang++ -Wall -Wextra -Werror main/main.cpp span.cpp