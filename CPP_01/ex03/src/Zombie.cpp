/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:12:01 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 16:37:03 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// Constructor and Destructor
//	To protect "There is no any default constructor for "Zombie" class
Zombie::Zombie()
{
	return;
}

Zombie::Zombie(std::string zombieType, std::string zombieName, std::string zombieRemainingMember)
	: _zombieType(zombieType), _zombieName(zombieName), _zombieRemainingMember(zombieRemainingMember)
{
	std::cout << T_BB "Zombie constructor called" T_N << std::endl;
	std::cout << T_GYB "Oh oh...";
	std::cout << this->_zombieName << " is coming for you..." << std::endl;
	return ;
}

Zombie::~Zombie ( void )
{
	std::cout << T_BB "Zombie destructor called" T_N << std::endl;
	std::cout << T_GNB "You did it ! One zombie dead.\n" T_N << std::endl;
	return ;
}


// Setters and Getters

void	Zombie::setZombieType( std::string type )
{
	this->_zombieType = type;
}

std::string	Zombie::getZombieType( void ) const
{
	return (this->_zombieType);
}

void	Zombie::setZombieName ( std::string name )
{
	 this->_zombieName = name;
}

std::string	Zombie::getZombieName( void ) const
{
	return (this->_zombieName);
}

void Zombie::setZombieRemainingMember( std::string remainingMember )
{
	this->_zombieRemainingMember = remainingMember;
}

std::string	Zombie::getZombieRemainingMember( void ) const
{
	return (this->_zombieRemainingMember);
}


// Zombie Announce
std::string Zombie::advert( void )
{
	return (T_GYB "<" + getZombieName() + " (" + getZombieType() + ", " + getZombieRemainingMember() 
		+ ")> " + T_R "Braiiiiiiinnnssss ...\n" T_N);
}

void	Zombie::announce( void )
{
	std::cout << advert();
}
