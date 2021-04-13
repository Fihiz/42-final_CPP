/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChocoboMoogle.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:41:20 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/10 22:40:21 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ChocoboMoogle.hpp"

// COPLIEN FORM 

ChocoboMoogle::ChocoboMoogle( void ) : AMateria("chocobo & moogle")
{
	return ;
}

ChocoboMoogle::ChocoboMoogle( ChocoboMoogle const &src )
{
	*this = src;
	return ;
}

// While assigning a Materia to another, copying the type doesn’t make sense...
ChocoboMoogle &ChocoboMoogle::operator=( ChocoboMoogle const &rhs )
{
	this->_xp = rhs._xp;
	return (*this); // Returning a reference(&ChocoboMoogle), so I dereference my pointer
}

ChocoboMoogle::~ChocoboMoogle( void )
{
	return ;
}


// METHODS

AMateria	*ChocoboMoogle::clone( void ) const
{
	return (new ChocoboMoogle(*this)); // May generate a different/new pointer/instance with this->_type
}

void		ChocoboMoogle::use( ICharacter &target )
{
	std::cout << T_GYB "* invokes Chocobo & Moogle to attack " << target.getName() << " *" T_N <<std::endl;
	AMateria::use(target);
	return ;
}