/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:46:56 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 11:39:39 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AWeapon.hpp"

// COPLIEN FORM

AWeapon::AWeapon( void )
{
	std::cout << T_GYHID "AWeapon Default constructor called" T_N << std::endl;
	return ;
}

AWeapon::AWeapon( std::string const &name, int apcost, int damage ) :
	_name(name),
	_APcost(apcost),
	_damage(damage)
{
	return ;
}

AWeapon::AWeapon( AWeapon const &src )
{
	std::cout << T_GYHID "AWeapon Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getName() << ", has been created by copy!" T_N << std::endl;
	return ;
}

AWeapon &AWeapon::operator=( AWeapon const &rhs )
{
	std::cout << T_GYHID "AWeapon Assignation operator called" T_N << std::endl;
	this->_name = rhs.getName();
	this->_APcost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	return (*this); // Returning a reference(&AWeapon), so I dereference my pointer
}

AWeapon::~AWeapon()
{
	return ;
}


// GETTERS

std::string	const	AWeapon::getName( void ) const
{
	return (this->_name);
}

int					AWeapon::getAPCost( void ) const
{
	return (this->_APcost);
}

int					AWeapon::getDamage( void ) const
{
	return (this->_damage);
}

// METHODS

/* No definition/implementation of attack method, it is a pure function.
** It's just a way to factor certain behavior as the ability to attack in our case,
** this is the daughter's classes that will must implement it, 
** cause the mother doesn't have a defined one. */
