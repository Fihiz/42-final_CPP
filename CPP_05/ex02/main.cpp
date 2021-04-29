/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:35:44 by salome            #+#    #+#             */
/*   Updated: 2021/04/14 21:13:35 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

void	testingSign(Bureaucrat &src1, AForm &src2)
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

void	testingForm(AForm &src)
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

void	testingExecute(AForm &form, Bureaucrat &executor)
{
	try
	{
		//form.execute(executor);
		executor.executeForm(form);
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

	srand (time(NULL));
	
	std::cout << T_BB "\n\t\tHow to execute a form for a Bureaucrat...\n" T_N;
	std::cout << std::endl << std::endl;
	
	// Testing Robotomy
	try
	{
		// One Bureaucrat
		Bureaucrat  braddy("Braddy", 46);
		// Another Bureaucrat
		Bureaucrat  andrew("Andrew Laeddis", 150);
		testingBureaucrat(braddy);
		testingBureaucrat(andrew);
		std::cout << std::endl;

		// One Form
		RobotomyRequestForm	oneForm(andrew.getName());
		testingForm(oneForm);
		std::cout << std::endl;

		// Braddy can sign but cannot execute it yet
		testingSign(braddy, oneForm);
		testingForm(oneForm);
		std::cout << std::endl;
		
		// Now incrementing braddy to be able to execute
		testingInc(braddy);
		testingBureaucrat(braddy);
		testingExecute(oneForm, braddy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;

	// Testing Shrubbery
	try
	{
		// One Bureaucrat
		Bureaucrat  braddy("Braddy", 37);
		// Another Bureaucrat
		Bureaucrat  andrew("Andrew Laeddis", 145);
		testingBureaucrat(braddy);
		testingBureaucrat(andrew);
		std::cout << std::endl;

		// One Form
		ShrubberyCreationForm oneForm(andrew.getName());
		testingForm(oneForm);
		std::cout << std::endl;

		// Andrew can sign but cannot execute it
		testingSign(andrew, oneForm);
		testingForm(oneForm);

		testingExecute(oneForm, braddy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;

	// Testing Presidential pardon
	try
	{
		// One Bureaucrat
		Bureaucrat  braddy("Braddy", 5);
		// Another Bureaucrat
		Bureaucrat  andrew("Chirac", 24);
		testingBureaucrat(braddy);
		testingBureaucrat(andrew);
		std::cout << std::endl;

		// One Form
		PresidentialPardonForm oneForm(andrew.getName());
		testingForm(oneForm);
		std::cout << std::endl;

		// Andrew can sign but cannot execute it
		testingSign(andrew, oneForm);
		testingForm(oneForm);
		std::cout << std::endl;

		testingExecute(oneForm, braddy);
		// Now Braddy can't execute the form anymore
		testingDec(braddy);
		testingBureaucrat(braddy);
		testingExecute(oneForm, braddy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;

	// Testing unsigned before execution
	try
	{
		// One Bureaucrat
		Bureaucrat  braddy("Braddy", 72);
		// Another Bureaucrat
		Bureaucrat  june("june", 3);

		// One Form
		PresidentialPardonForm oneForm("Biden");
		testingForm(oneForm);
		std::cout << std::endl;

		// Another Form
		RobotomyRequestForm twoForm("June");
		testingForm(twoForm);
		std::cout << std::endl;

		// Another Form
		ShrubberyCreationForm threeForm("Elon");
		testingForm(threeForm);
		std::cout << std::endl;

		// Failure
		testingSign(braddy, oneForm);
		testingSign(june, oneForm);
		testingSign(braddy, twoForm);
		// Already signed
		testingSign(june, twoForm);
		testingSign(june, threeForm);

		// Failure
		testingExecute(twoForm, braddy);
		testingExecute(twoForm, june);
		testingExecute(threeForm, june);
		//testingExecute(oneForm, braddy);
		//std::cout << std::endl;

		//testingSign(braddy, oneForm);
		//testingExecute(oneForm, braddy);
		//std::cout << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	//try
	//{
	//	Bureaucrat original("Origin", 1);
	//	Bureaucrat assign("Assign", 150);
	//	Bureaucrat copy(original);
	//	assign = original;
	//	//testingBureaucrat(original);
	//	//testingBureaucrat(assign);
	//	//testingBureaucrat(copy);

	//	std::cout << std::endl << std::endl;
	//	RobotomyRequestForm a(copy.getName());
	//	RobotomyRequestForm b(assign.getName());
	//	RobotomyRequestForm c(a);

	//	b = a;
	//	testingForm(a);
	//	testingForm(b);
	//	testingForm(c);
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}
	return (0);
}