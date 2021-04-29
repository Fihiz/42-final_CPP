/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:06:35 by salome            #+#    #+#             */
/*   Updated: 2021/04/14 21:47:58 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/Intern.hpp"

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

int main()
{
	srand (time(NULL));
	
	std::cout << T_BB "\n\t\tHow to delegate for a Bureaucrat...\n" T_N;
	std::cout << std::endl << std::endl;
	
	Intern someRandomIntern;
	AForm* rrf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	AForm* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Billy");

	AForm* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Donald");

	AForm* wrong;
	wrong = someRandomIntern.makeForm("presidential joke", "Harry");

	// Testing Robotomy
	try
	{
		// One Bureaucrat
		Bureaucrat  braddy("Braddy", 46);

		if (rrf)
		{
			testingForm(*rrf); // Accessing to pointer type (shrubbery, robotomy, presidential...)
			testingExecute(*rrf, braddy);
			testingInc(braddy);
			testingExecute(*rrf, braddy);
			testingSign(braddy, *rrf); // We finally try to robotomize Bender
			testingExecute(*rrf, braddy);
			testingSign(braddy, *rrf); // We finally try to robotomize Bender
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;

	// Testing Presidential Pardon
	try
	{
		// One Bureaucrat
		Bureaucrat  braddy("Braddy", 1);

		if (ppf)
		{
			testingForm(*ppf); // Accessing to pointer type (shrubbery, robotomy, presidential...)
			testingExecute(*ppf, braddy);
			testingExecute(*ppf, braddy); // Not signed yet
			testingSign(braddy, *ppf);
			testingExecute(*ppf, braddy);
			testingSign(braddy, *ppf); // Already signed case
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;

	// Testing Shrubbery Creation
	try
	{
		// One Bureaucrat
		Bureaucrat  braddy("Braddy", 18);

		if (scf)
		{
			testingForm(*scf); // Accessing to pointer type (shrubbery, robotomy, presidential...)
			testingExecute(*scf, braddy);
			testingSign(braddy, *scf);
			testingExecute(*scf, braddy);
			testingSign(braddy, *scf);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;

	// Testing Wrong
	try
	{
		if (wrong)
		{
			testingForm(*wrong);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;

	delete rrf;
	delete scf;
	delete ppf;
	return (0);
}