/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:26:14 by salome            #+#    #+#             */
/*   Updated: 2021/04/07 11:11:34 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PowerFist.hpp"

// COPLIEN FORM

PowerFist::PowerFist( void ) : AWeapon("Power Fist", 8, 50)
{
	return ;
}

PowerFist::PowerFist( PowerFist const &src )
{
	std::cout << T_GYHID "PowerFist Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getName() << ", has been created by copy!" T_N << std::endl;
	return ;
}

PowerFist &PowerFist::operator=( PowerFist const &rhs )
{
	std::cout << T_GYHID "PowerFist Assignation operator called" T_N << std::endl;
	this->_name = rhs.getName();
	this->_APcost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	return (*this); // Returning a reference(&PowerFist), so I dereference my pointer
}

PowerFist::~PowerFist()
{
	return ;
}

// METHODS

/* The PowerFist, which is a AWeapon's child class, 
** has to define the pure method of her mother, it means the attack method. */

void 	PowerFist::attack( void ) const
{
	std::cout << T_R "* pschhh... SBAM! *" T_N << std::endl;
}
