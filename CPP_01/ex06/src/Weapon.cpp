/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:24:45 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 15:00:02 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon( void )
{
	std::cout << T_BB "Weapon Constructor called" T_N << std::endl;
	return ;
}

Weapon::Weapon( std::string type ) : _type(type) //Initialize
{
	return ;
}

Weapon::~Weapon()
{
	std::cout << T_BB "Weapon Destructor called" T_N << std::endl;
	return ;
}

void	Weapon::setType( std::string const &type)
{
	this->_type = type;
}

std::string const &Weapon::getType( void ) const //Returns a const ref of type (think to char * and return)
{
	return (this->_type); //Return type val 
}