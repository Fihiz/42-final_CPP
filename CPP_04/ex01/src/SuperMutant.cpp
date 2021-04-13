/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:30:02 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/11 11:46:50 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SuperMutant.hpp"

// COPLIEN FORM

SuperMutant::SuperMutant( void ) : Enemy( 170, "Super Mutant" ) // Calling "hp and type" enemy constructor
{
    std::cout << T_GYHID "Gaaah. Me want smash heads!" T_N << std::endl;
	return ;
}

SuperMutant::SuperMutant( SuperMutant const &src )
{
	std::cout << T_GYHID "SuperMutant Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getType() << ", has been created by copy!" T_N << std::endl;
	return ;
}

SuperMutant &SuperMutant::operator=( SuperMutant const &rhs )
{
	std::cout << T_GYHID "SuperMutant Assignation operator called" T_N << std::endl;
	this->_HP = rhs.getHP();
	this->_type = rhs.getType();
	return (*this); // Returning a reference(&SuperMutant), so I dereference my pointer
}

SuperMutant::~SuperMutant()
{
	std::cout << T_BB "Aaargh..." T_N << std::endl;
	return ;
}

// METHODS

void        SuperMutant::takeDamage( int damage )
{
	Enemy::takeDamage(damage - 3);
	return ;
}
