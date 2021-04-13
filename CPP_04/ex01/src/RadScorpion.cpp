/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:42:49 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/09 14:35:10 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RadScorpion.hpp"

// COPLIEN FORM

RadScorpion::RadScorpion( void ) : Enemy( 80, "RadScorpion" )	// Calling "hp and type" enemy constructor
{
    std::cout << T_GYHID "* click click click *" T_N << std::endl;
	return ;
}

RadScorpion::RadScorpion( RadScorpion const &src )
{
	std::cout << T_GYHID "RadScorpion Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getType() << ", has been created by copy!" T_N << std::endl;
	return ;
}

RadScorpion &RadScorpion::operator=( RadScorpion const &rhs )
{
	std::cout << T_GYHID "RadScorpion Assignation operator called" T_N << std::endl;
	this->_HP = rhs.getHP();
	this->_type = rhs.getType();
	return (*this); // Returning a reference(&RadScorpion), so I dereference my pointer
}

RadScorpion::~RadScorpion()
{
	std::cout << T_BB "* SPROTCH *" T_N << std::endl;
	return ;
}
