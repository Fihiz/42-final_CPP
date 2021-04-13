/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 07:42:21 by salome            #+#    #+#             */
/*   Updated: 2021/04/10 22:40:17 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

// COPLIEN FORM 

Ice::Ice( void ) : AMateria("ice")
{
	return ;
}

Ice::Ice( Ice const &src )
{
	*this = src;
	return ;
}

// While assigning a Materia to another, copying the type doesn’t make sense...
Ice &Ice::operator=( Ice const &rhs )
{
	this->_xp = rhs._xp;
	return (*this); // Returning a reference(&Sorcerer), so I dereference my pointer
}

Ice::~Ice( void )
{
	return ;
}


// METHODS

AMateria	*Ice::clone( void ) const
{
	return (new Ice(*this)); // May generate a different/new pointer/instance with this->_type
}

void		Ice::use( ICharacter &target )
{
	std::cout << T_GYB "* shoots an ice bolt at " << target.getName() << " *" T_N <<std::endl;
	AMateria::use(target);
	return ;
}

