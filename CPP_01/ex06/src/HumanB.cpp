/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:24:34 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 11:15:37 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB( std::string name ) : _bName(name), _bWeapon()
{
	std::cout << T_BB "HumanB Constructor called" T_N << std::endl;
	//constructor for 'HumanB' must explicitly initialize the reference member '_bWeapon'
	return;
}

HumanB::~HumanB()
{
	std::cout << T_BB "HumanB Destructor called" T_N << std::endl;
	return ;
}

void	HumanB::attack( void )
{
	std::cout << T_CB << this->_bName << T_GYB " attacks with his " T_CB << this->_bWeapon->getType() << T_N << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon) 
{
	this->_bWeapon = &weapon; //Assigning to 'Weapon *' from incompatible type 'Weapon'; take the address with & -> initialize on weapon address
}