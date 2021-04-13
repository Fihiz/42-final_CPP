/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:00:36 by salome            #+#    #+#             */
/*   Updated: 2021/04/10 22:40:58 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

// COPLIEN FORM

AMateria::AMateria( void )
{
	return ;
}

AMateria::AMateria( std::string const &type ) :
	_type(type), _xp(0)
{
	return ;
}

AMateria::AMateria( AMateria const &src )
{
	std::cout << T_GYHID "AMateria Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	return ;
}

AMateria &AMateria::operator=( AMateria const &rhs )
{
	std::cout << T_GYHID "AMateria Assignation operator called" T_N << std::endl;
	this->_type = rhs.getType();
	this->_xp = rhs.getXP();
	return (*this); // Returning a reference(&Peon), so I dereference my pointer
}

AMateria::~AMateria( void )
{
	std::cout << T_GYHID "AMateria Desctructor called" T_N << std::endl;
	return ;
}


// GETTERS

std::string const &AMateria::getType( void ) const
{
	return (this->_type);
}

unsigned int AMateria::getXP( void ) const
{
	return (this->_xp);
}


// METHODS

void AMateria::use( ICharacter& target )
{
	std::cout << T_GY "The more a Materia is invoked on a target, like " << target.getName() << ", the more experience it gains..." T_N << std::endl;
	this->_xp += 10;
}