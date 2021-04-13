/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:06:21 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/11 11:52:36 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

// COPLIEN FORM

Character::Character( void )
{
	return ;
}

Character::Character( std::string const & name ) :
    _name(name)
{
    this->_AP = 40;
	this->_weapon = NULL;
    return ;
}

Character::Character( Character const &src )
{
	std::cout << T_GYHID "Character Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getName() << ", has been created by copy!" T_N << std::endl;
	return ;
}

Character &Character::operator=( Character const &rhs )
{
	std::cout << T_GYHID "Character Assignation operator called" T_N << std::endl;
	this->_name = rhs.getName();
	this->_AP = rhs.getAP();
    this->_weapon = rhs.getWeapon();
	return (*this); // Returning a reference(&Character), so I dereference my pointer
}

Character::~Character()
{
	return ;
}


// GETTERS

std::string	const	Character::getName( void ) const
{
	return (this->_name);
}

int					Character::getAP( void ) const
{
	return (this->_AP);
}

AWeapon				*Character::getWeapon( void ) const
{
    return (this->_weapon);
}


// Methods

std::ostream	&operator<<( std::ostream &o, const Character &rhs )
{
	if (rhs.getWeapon())
		o << T_GY << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	else
		o << T_GY << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
	return (o);
}

void 				Character::recoverAP( void )
{
	int	toRecover = 10;

	if (this->_AP + toRecover > 40)
		toRecover = 40 - this->_AP;
	this->_AP += toRecover;
	return ;
}

void 				Character::equip( AWeapon* arm)
{
	this->_weapon = arm; // Just store a pointer to the weapon, there’s no copy involved
	return ;
}

void 				Character::attack( Enemy* enemy)  // Overload
{
	if (this->_weapon)
	{
		int	APcost = this->_weapon->getAPCost();

		if (this->_AP < APcost)
			std::cout << T_GYB "No AP, no attack." T_N << std::endl; // Attack fails if there isn't enough AP
		else if (this->_weapon)
		{
			std::cout << T_GYB << getName() << " attacks " << enemy->getType();
			std::cout << " with a " << this->_weapon->getName() << T_N << std::endl;

			this->_AP -= APcost;
			this->_weapon->attack();
			enemy->takeDamage(this->_weapon->getDamage());
			if (enemy->getHP() <= 0)
				delete enemy;
		}
	}
	else // Else if, there is not any equiped weapon, attack does nothing
		std::cout << T_GYB "No Weapon, no attack." T_N << std::endl;
}

void	Character::characterStatusBar( void )	// Additional function to make my main clearer
{
	std::cout << T_GYB "CHARACTER BAR < " T_BB << getName() << T_GYB << ", AP(" T_BB;
	std::cout << getAP()  << T_GYB ") > " T_N;
	return ;
}