/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WaterZombie.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:51:41 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/09 15:55:17 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WaterZombie.hpp"

// COPLIEN FORM

WaterZombie::WaterZombie( void ) : Enemy( 40, "WaterZombie" )	// Calling "hp and type" enemy constructor
{
    std::cout << T_GYHID "* brain fishhhhh *" T_N << std::endl;
	return ;
}

WaterZombie::WaterZombie( WaterZombie const &src )
{
	std::cout << T_GYHID "WaterZombie Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getType() << ", has been created by copy!" T_N << std::endl;
	return ;
}

WaterZombie &WaterZombie::operator=( WaterZombie const &rhs )
{
	std::cout << T_GYHID "WaterZombie Assignation operator called" T_N << std::endl;
	this->_HP = rhs.getHP();
	this->_type = rhs.getType();
	return (*this); // Returning a reference(&WaterZombie), so I dereference my pointer
}

WaterZombie::~WaterZombie()
{
	std::cout << T_BB "* PLOUF *" T_N << std::endl;
	return ;
}
