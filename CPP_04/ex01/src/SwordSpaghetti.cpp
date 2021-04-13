/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SwordSpaghetti.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:15:58 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/09 15:36:46 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SwordSpaghetti.hpp"

// COPLIEN FORM

SwordSpaghetti::SwordSpaghetti( void ) : AWeapon("SwordSpaghetti", 4, 18)
{
	return ;
}

SwordSpaghetti::SwordSpaghetti( SwordSpaghetti const &src )
{
	std::cout << T_GYHID "SwordSpaghetti Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getName() << ", has been created by copy!" T_N << std::endl;
	return ;
}

SwordSpaghetti &SwordSpaghetti::operator=( SwordSpaghetti const &rhs )
{
	std::cout << T_GYHID "SwordSpaghetti Assignation operator called" T_N << std::endl;
	this->_name = rhs.getName();
	this->_APcost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	return (*this); // Returning a reference(&SwordSpaghetti), so I dereference my pointer
}

SwordSpaghetti::~SwordSpaghetti()
{
	return ;
}

// METHODS

/* The SwordSpaghetti, which is a AWeapon's child class, 
** has to define the pure method of her mother, it means the attack method. */

void 	SwordSpaghetti::attack( void ) const
{
	std::cout << T_R "* carbo carbo carbonaaarrrrrrraaaaaa *" T_N << std::endl;
}
