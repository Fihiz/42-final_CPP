/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Toad.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:25:21 by salome            #+#    #+#             */
/*   Updated: 2021/04/05 10:26:57 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Toad.hpp"

// COPLIEN FORM

Toad::Toad( void )
{
	return ;
}

Toad::Toad( std::string const &name ) : Victim(name) // Calling Victim Name constructor
{
	std::cout << T_GY T_I "Kroa kroa." << std::endl;
	return ;
}


// NEED TO TEST COPLIEN INHERITANCE

Toad::Toad( Toad const &src )
{
	std::cout << T_GYHID "Toad Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getName() << ", is born by copy!" T_N << std::endl;
	return ;
}

Toad &Toad::operator=( Toad const &rhs )
{
	std::cout << T_GYHID "Toad Assignation operator called" T_N << std::endl;
	this->_name = rhs.getName();
	return (*this); // Returning a reference(&Toad), so I dereference my pointer
}

Toad::~Toad()
{
	std::cout << T_BB "Kroark..." T_N << std::endl;
	return ;
}


// METHODS

void			Toad::getPolymorphed( void ) const
{
	std::cout << T_PU << getName() << " has been turned into a princess!" T_N << std::endl;
}