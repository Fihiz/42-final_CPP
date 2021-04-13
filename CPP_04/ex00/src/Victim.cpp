/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:47:16 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 11:23:39 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Victim.hpp"

// COPLIEN FORM

Victim::Victim( void )
{
	return ;
}

Victim::Victim( std::string const &name ) : _name(name)
{
	std::cout << T_BB "Some random victim called " << getName() << " just appeared!" T_N << std::endl;
	return ;
}

Victim::Victim( Victim const &src )
{
	std::cout << T_GYHID "Victim Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getName() << ", is born by copy!" T_N << std::endl;
	return ;
}

Victim &Victim::operator=( Victim const &rhs )
{
	std::cout << T_GYHID "Victim Assignation operator called" T_N << std::endl;
	this->_name = rhs.getName();
	return (*this); // Returning a reference(&Victim), so I dereference my pointer
}

Victim::~Victim()
{
	std::cout << T_BB << "The victim " << getName() << " died for not apparent reasons!" T_N << std::endl;
	return ;
}


// GETTERS

std::string		Victim::getName( void ) const
{
	return (this->_name);
}


// METHODS

std::ostream &operator<<( std::ostream &o, const Victim &rhs ) // An overload to the [«] operator that inserts a victim introduction into the parameter output stream
{
	o << T_GYB T_I "I am " << rhs.getName() << " and I like otters!" T_N << std::endl;
    return (o);
}

void			Victim::getPolymorphed( void ) const
{
	std::cout << T_PU << getName() << " has been turned into a cute little sheep!" T_N << std::endl;
	return ;
}