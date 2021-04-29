/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:09:56 by salome            #+#    #+#             */
/*   Updated: 2021/04/14 21:45:54 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

// COPLIEN FORM

Intern::Intern( void )
{
	std::cout << T_GYHID "Intern constructor called" T_N << std::endl;
	return ;
}

Intern::Intern( Intern const &src )
{
	std::cout << T_GYHID "Intern Copy constructor called" T_N << std::endl;
	(void)src;
	*this = src;
}

Intern &Intern::operator=( Intern const &rhs )
{
	std::cout << T_GYHID "Intern Assignation operator overload called" T_N << std::endl;
	(void)rhs;
	return (*this);
}

Intern::~Intern( void )
{
	std::cout << T_GYHID "Intern destructor called" T_N << std::endl;
	return ;
}

// METHODS
AForm	*Intern::makeForm( std::string const formName, std::string const formTarget )
{	
	// Remember we have a base class AForm whihch has [3] derived formTypes, that only take one target in their constructor
	AForm *(Intern::* formTypes[3])(std::string const target); // AForm *Intern::(3possibletypes)(onetarget);

	// Storing our 3 AForm member functions for form creation in a tab
	formTypes[0] = &Intern::_makeShrubberyForm;
	formTypes[1] = &Intern::_makeRobotomyForm;
	formTypes[2] = &Intern::_makePresidentialPardonForm;
	
	for (int i = 0; i < 3; i++)
		if (formName == _formNames[i]) // Match finding
			return ((this->*formTypes[i])(formTarget)); // Now calling the good makeTypeForm creation matching indexes
	std::cout << T_Y "The Form Name is corrupted. Intern cannot validate the procedure." T_N << std::endl;
	return (NULL);
}

AForm	*Intern::_makeShrubberyForm( std::string const target )
{
	ShrubberyCreationForm* oneForm = new ShrubberyCreationForm( target );
	std::cout << T_GY "Intern creates " T_BB << oneForm->getName() << ". " T_N << std::endl;
	return (oneForm);
}

AForm	*Intern::_makeRobotomyForm( std::string const target )
{
	RobotomyRequestForm* oneForm = new RobotomyRequestForm( target );
	std::cout << T_GY "Intern creates " T_BB << oneForm->getName() << ". " T_N << std::endl;
	return (oneForm);
}

AForm	*Intern::_makePresidentialPardonForm( std::string const target )
{
	PresidentialPardonForm* oneForm = new PresidentialPardonForm( target );
	std::cout << T_GY "Intern creates " T_BB << oneForm->getName() << ". " T_N << std::endl;
	return (oneForm);
}

// STATIC FORM NAMES
std::string Intern::_formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};