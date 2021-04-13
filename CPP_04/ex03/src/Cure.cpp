/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 07:43:52 by salome            #+#    #+#             */
/*   Updated: 2021/04/10 22:33:43 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

// COPLIEN FORM 

Cure::Cure( void ) : AMateria("cure")
{
	return ;
}

Cure::Cure( Cure const &src )
{
	*this = src;
	return ;
}

// While assigning a Materia to another, copying the type doesn’t make sense...
Cure &Cure::operator=( Cure const &rhs )
{
	this->_xp = rhs._xp;
	return (*this); // Returning a reference(&Cure), so I dereference my pointer
}

Cure::~Cure( void )
{
	return ;
}


// METHODS

AMateria	*Cure::clone( void ) const
{
	return (new Cure(*this)); // May generate a different/new pointer/instance with this->_type
}

void		Cure::use( ICharacter &target )
{
	std::cout << T_GYB "* heals " << target.getName() << "’s wounds * " T_N <<std::endl;
	AMateria::use(target);
	return ;
}