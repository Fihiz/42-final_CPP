/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:54:20 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 09:52:36 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ZombieEvent.hpp"

// Constructor and Destructor
ZombieEvent::ZombieEvent( void )
{
	std::cout << T_BB "ZombieEvent constructor called" T_N << std::endl;
	return ;
}

ZombieEvent::~ZombieEvent ( void )
{
	std::cout << T_BB "ZombieEvent destructor called" T_N << std::endl;
	return ;
}


// Setters and Getters
void	ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

void	ZombieEvent::setZombieRemainingMember(std::string remaingingMember)
{
	this->_remainingMember = remaingingMember;
}


// Zombie Creator
Zombie *ZombieEvent::newZombie (std::string name)
{
	//My [this] pointer inherits from previous main scope initialization
	return (new Zombie(this->_type, name, this->_remainingMember)); //Calls my Zombie Constructor with my three attributes
}

Zombie *ZombieEvent::randomChump( void )
{	
	Zombie *zombieChump;

	//Random seed for zombie name
	std::string names[5] = {"Cypher", "Bloom", "Freeze", "Fara", "Flesh"};
	srand (time(NULL));

	zombieChump = newZombie(names[rand() % 5]);
	zombieChump->announce();
	return (zombieChump);
}