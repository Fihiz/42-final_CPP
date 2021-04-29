/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:27:13 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/14 18:25:41 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

// COPLIEN FORM

RobotomyRequestForm::RobotomyRequestForm( std::string const &target ) :
	AForm("Robotomy Request Form", 72, 45)
{
	setTarget(target);
	std::cout << T_GYHID "RobotomyRequestForm Name and Grade constructor called,";
	std::cout << " having " << getTarget() << " for target" << T_N << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src ) :
	AForm(src)
{
	std::cout << T_GYHID "RobotomyRequestForm Copy constructor called" T_N << std::endl;
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs )
{
	std::cout << T_GYHID "RobotomyRequestForm Assignation operator overload called" T_N << std::endl;
	rhs.getName();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << T_GYHID "RobotomyRequestForm destructor called" T_N << std::endl;
	return ;
}

// METHODS

void	RobotomyRequestForm::execute( Bureaucrat const &executor ) const
{
	AForm::execute(executor); // Calling pure virtual function
	// Now overrinding
	std::cout << T_R "* DRRRR DRRRIIII DRIIIIILL NOISE* " T_N << std::endl;
	if ((rand() % 100) > 50)
		std::cout << T_BB << getTarget() << T_GY " has been robotomized successfully." T_N << std::endl;
	else
		std::cout << T_GY "Unfortunately, Robotomy has been a failure for " T_BB << getTarget() << T_GY "." T_N << std::endl;
	return ;
}
