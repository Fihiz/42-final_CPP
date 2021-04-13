/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:24:05 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 00:13:03 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _aName(name), _aWeapon(weapon)
{
	std::cout << T_BB "HumanA Constructor called" T_N << std::endl;
	return;
}

HumanA::~HumanA()
{
	std::cout << T_BB "HumanA Destructor called" T_N << std::endl;
	return ;
}

void	HumanA::attack( void )
{
	std::cout << T_CB << this->_aName << T_GYB " attacks with his " T_CB << this->_aWeapon.getType() << T_N << std::endl;
}