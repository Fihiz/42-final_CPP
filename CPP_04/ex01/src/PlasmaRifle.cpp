/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:23:41 by salome            #+#    #+#             */
/*   Updated: 2021/04/07 11:10:54 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PlasmaRifle.hpp"

// COPLIEN FORM

PlasmaRifle::PlasmaRifle( void ) : AWeapon("Plasma Rifle", 5, 21)
{
	return ;
}

PlasmaRifle::PlasmaRifle( PlasmaRifle const &src )
{
	std::cout << T_GYHID "PlasmaRifle Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getName() << ", has been created by copy!" T_N << std::endl;
	return ;
}

PlasmaRifle &PlasmaRifle::operator=( PlasmaRifle const &rhs )
{
	std::cout << T_GYHID "PlasmaRifle Assignation operator called" T_N << std::endl;
	this->_name = rhs.getName();
	this->_APcost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	return (*this); // Returning a reference(&PlasmaRifle), so I dereference my pointer
}

PlasmaRifle::~PlasmaRifle()
{
	return ;
}

// METHODS

/* The PlasmaRifle, which is a AWeapon's child class, 
** has to define the pure method of her mother, it means the attack method. */

void 	PlasmaRifle::attack( void ) const
{
	std::cout << T_R "* piouuu piouuu piouuu *" T_N << std::endl;
}
