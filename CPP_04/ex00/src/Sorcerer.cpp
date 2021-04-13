/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:47:13 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 11:24:04 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Sorcerer.hpp"


// COPLIEN FORM

Sorcerer::Sorcerer( void )
{
	// My default constructor is currently a private member
	return ;
}

Sorcerer::Sorcerer( std::string const &name, std::string const &title ) :
	_name(name),
	_title(title)
{
	std::cout << T_BB << getIdentity() << ", is born!" T_N << std::endl;
	return ;
}

Sorcerer::Sorcerer( Sorcerer const &src )
{
	std::cout << T_GYHID "Sorcerer Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getIdentity() << ", is born by copy!" T_N << std::endl;
	return ;
}

Sorcerer &Sorcerer::operator=( Sorcerer const &rhs )
{
	std::cout << T_GYHID "Sorcerer Assignation operator called" T_N << std::endl;
	this->_name = rhs.getName();
	this->_title = rhs.getTitle();
	return (*this); // Returning a reference(&Sorcerer), so I dereference my pointer
}

Sorcerer::~Sorcerer()
{
	std::cout << T_BB << getIdentity() << ", is dead. Consequences will never be the same!" T_N << std::endl;
	return ;
}


// GETTERS

std::string		Sorcerer::getName( void ) const
{
	return (this->_name);
}

std::string		Sorcerer::getTitle( void ) const
{
	return (this->_title);
}

std::string		Sorcerer::getIdentity( void ) const
{
	return(getName() + ", " + getTitle()); 
}


// METHODS

std::ostream &operator<<( std::ostream &o, const Sorcerer &rhs ) // An overload to the [«] operator that inserts a sorcerer introduction into the parameter output stream
{
	o << T_GYB T_I "I am " << rhs.getIdentity() << ", and i like ponies!" T_N << std::endl;
    return (o);
}

void		Sorcerer::polymorph( Victim const &victim) const
{
	victim.getPolymorphed(); // Calling getPolymorphed into Victim object
	return ;
}