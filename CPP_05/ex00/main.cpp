/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:35:54 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/12 21:34:55 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	testingInc(Bureaucrat &src)
{
	try
	{
		src.incGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	testingDec(Bureaucrat &src)
{
	try
	{
		src.decGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int     main()
{
	/* When I instantiate an object through a Try scope,
	** it is destroyed at the end of the try scope */

	
	std::cout << T_BB "\n\t\tWelcome to this world of bureaucrats...\n";
	std::cout << "\tLet's begin by testing our Constructor's grade limits\n" T_N << std::endl;

	// Trying a too high grade
	try
	{
		Bureaucrat  tooHigh("Braddy", 0);
		std::cout << tooHigh;
		
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	// Trying a too low grade
	try
	{
		Bureaucrat  tooLow("Peter", 151);
		std::cout << tooLow;
		
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	// Trying another wrong grade
	try
	{
		Bureaucrat  polly("Polly", -5);
		std::cout << polly;
		
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	// Trying another wrong grade
	try
	{
		Bureaucrat  polly("Polly", -150);
		std::cout << polly;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << T_BB "\tNow let's try to promote our employees" T_N << std::endl;
	// Trying a good grade
	try
	{
		std::cout << std::endl;
		Bureaucrat  bobby("Bobby", 10);
		std::cout << bobby;
		
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	// Trying another good grade
	try
	{
		Bureaucrat  lewis("Lewis", 150);
		std::cout << lewis;
		// Nesting our tests
		testingInc(lewis);
		testingInc(lewis);
		testingInc(lewis);
		std::cout << lewis;
		testingDec(lewis);
		testingDec(lewis);
		testingDec(lewis);
		std::cout << lewis;
		testingDec(lewis);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	// Trying another good grade
	try
	{
		Bureaucrat  lewis("Lewis", 1);
		std::cout << lewis;
		// Nesting our tests
		testingInc(lewis);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	//try
	//{
	//	Bureaucrat original("Origin", 1);
	//	Bureaucrat assign("Assign", 150);
	//	Bureaucrat copy(original);
	//	assign = original;
	//	std::cout << original;
	//	std::cout << assign;
	//	std::cout << copy;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}

    return (0);
}

// Testing: clang++ -Wall -Wextra -Werror *.cpp
