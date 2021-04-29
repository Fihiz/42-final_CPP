/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:26:55 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/14 17:40:27 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

// COPLIEN FORM

PresidentialPardonForm:: PresidentialPardonForm( std::string const &target ) :
	AForm("Presidential Pardon Form", 25, 5)
{
	setTarget(target);
	std::cout << T_GYHID "PresidentialPardonForm Name and Grade constructor called,";
	std::cout << " having " << getTarget() << " for target" << T_N << std::endl;
	return ;
}

PresidentialPardonForm:: PresidentialPardonForm(  PresidentialPardonForm const &src ) :
	AForm(src)
{
	std::cout << T_GYHID "PresidentialPardonForm Copy constructor called" T_N << std::endl;
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(  PresidentialPardonForm const &rhs )
{
	std::cout << T_GYHID "PresidentialPardonForm Assignation operator overload called" T_N << std::endl;
	rhs.getName();
	return (*this);
}

PresidentialPardonForm::~ PresidentialPardonForm( void )
{
	std::cout << T_GYHID "PresidentialPardonForm destructor called" T_N << std::endl;
	return ;
}

// METHODS

void	 PresidentialPardonForm::execute( Bureaucrat const &executor ) const
{
	AForm::execute(executor); // Calling pure virtual function
	// Now overrinding
	std::cout << T_GY "< " << T_BB << getTarget() << T_GY " > has been pardoned by Zafod Beeblebrox." T_N << std::endl;
	return ;
}