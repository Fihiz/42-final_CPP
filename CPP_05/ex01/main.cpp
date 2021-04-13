/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 01:44:16 by salome            #+#    #+#             */
/*   Updated: 2021/04/13 11:56:06 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/Form.hpp"

void	testingSign(Bureaucrat &src1, Form &src2)
{
	try
	{
		src1.signForm(src2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	testingBureaucrat(Bureaucrat &src)
{
	try
	{
		std::cout << src;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testingForm(Form &src)
{
	try
	{
		std::cout << src;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

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

	
	std::cout << T_BB "\n\t\tHow to make a form for a Bureaucrat...\n" T_N;
	std::cout << std::endl << std::endl;
	
	try
	{
		// One Bureaucrat
		Bureaucrat  braddy("Braddy", 2);
		// Another Bureaucrat
		Bureaucrat  john("John", 150);
		testingBureaucrat(braddy);
		testingBureaucrat(john);
		std::cout << std::endl;

		Form	oneForm("Administrative", 149, 5);
		// One Form
		Form	twoForm("Payment", 1, 5);
		// Another Form
		testingForm(oneForm);
		testingForm(twoForm);
		std::cout << std::endl;
		
		//Incrementing to the good grade to be able to sign
		testingInc(braddy);
		testingBureaucrat(braddy);
		testingSign(braddy, twoForm);
		testingForm(twoForm);
		std::cout << std::endl;

		//Incrementing to the good grade to be able to sign
		testingInc(john);
		testingInc(john);
		testingSign(john, oneForm);
		testingForm(oneForm);
		std::cout << std::endl;
		
		//Already signed
		testingSign(braddy, oneForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << std::endl;
	try
	{
		//A wrong Bureaucrat
		Bureaucrat  polly("Polly", -150);
		testingBureaucrat(polly);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << std::endl;
	try
	{
		//A Bureaucrat
		Bureaucrat  polly("Polly", 12);
		testingBureaucrat(polly);

		Form	oneForm("Administrative", 11, 5);
		testingSign(polly, oneForm);
		testingForm(oneForm);

		// Now decrementing a Bureaucrat, won't be able anymore to manage form
		testingDec(polly);
		testingDec(polly);
		testingBureaucrat(polly);
		testingSign(polly, oneForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << std::endl;
	try
	{
		//A Bureaucrat
		Bureaucrat  polly("Polly", 10);
		testingBureaucrat(polly);

		Form	oneForm("Administrative", 11, 5);
		testingSign(polly, oneForm);
		testingForm(oneForm);

		// Now decrementing a Bureaucrat, won't be able anymore to manage form
		testingDec(polly);
		testingDec(polly);
		testingBureaucrat(polly);
		testingSign(polly, oneForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}