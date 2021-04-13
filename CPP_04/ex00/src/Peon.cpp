/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:47:11 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 11:23:21 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Peon.hpp"

// COPLIEN FORM

Peon::Peon( void )
{
	return ;
}

Peon::Peon( std::string const &name ) : Victim(name) // Calling Victim Name constructor
{
	std::cout << T_GY T_I "Zog zog." << std::endl;
	return ;
}

Peon::Peon( Peon const &src )
{
	std::cout << T_GYHID "Peon Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getName() << ", is born by copy!" T_N << std::endl;
	return ;
}

Peon &Peon::operator=( Peon const &rhs )
{
	std::cout << T_GYHID "Peon Assignation operator called" T_N << std::endl;
	this->_name = rhs.getName();
	return (*this); // Returning a reference(&Peon), so I dereference my pointer
}

Peon::~Peon()
{
	std::cout << T_BB "Bleuark..." T_N << std::endl;
	return ;
}


// METHODS

void			Peon::getPolymorphed( void ) const
{
	std::cout << T_PU << getName() << " has been turned into a pink pony!" T_N << std::endl;
	return ;
}