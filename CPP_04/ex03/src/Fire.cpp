/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:39:58 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/10 22:44:29 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fire.hpp"

// COPLIEN FORM 

Fire::Fire( void ) : AMateria("fire")
{
	return ;
}

Fire::Fire( Fire const &src )
{
	*this = src;
	return ;
}

// While assigning a Materia to another, copying the type doesn’t make sense...
Fire &Fire::operator=( Fire const &rhs )
{
	this->_xp = rhs._xp;
	return (*this); // Returning a reference(&Fire), so I dereference my pointer
}

Fire::~Fire( void )
{
	return ;
}


// METHODS

AMateria	*Fire::clone( void ) const
{
	return (new Fire(*this)); // May generate a different/new pointer/instance with this->_type
}

void		Fire::use( ICharacter &target )
{
	std::cout << T_GYB "* burns " << target.getName() << "’s hair *" T_N <<std::endl;
	AMateria::use(target); // Overloading
	return ;
}