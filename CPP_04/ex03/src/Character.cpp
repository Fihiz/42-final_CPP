/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 08:04:22 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 15:57:10 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

// COPLIEN FORM

Character::Character( void )
{
	return ;
}

Character::Character( std::string const &name ) : _name(name), _held(0), _heldMax(4)
{
	// The Character possesses an inventory of 4 Materia at most, empty at start
	for (int i = 0; i < _heldMax; i++)
		this->_inventory[i] = nullptr;
	return ;
}

Character::Character( Character const &src )
{
	*this = src;
	return ;
}

Character &Character::operator=( Character const &rhs )
{
	//std::cout << T_BHID "Character Overload Assignation called" T_N << std::endl;
	if (this == &rhs)
		return (*this);

	for (int i = 0; i < this->_heldMax; i++)
		delete this->_inventory[i];
	
	this->_name = rhs.getName();
	this->_held = rhs.getHeld();

	for (int i = 0; i < rhs.getHeld(); i++)
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone(); //this->_inventory[i] = rhs._inventory[i];
		else
			this->_inventory[i] = nullptr;
	return (*this);
}

Character::~Character( void )
{
	// When a Character is destroyed, his held stones are destroyed also, in order
	for (int i = 0; i < _held; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = nullptr;
	}
	return ;
}


// GETTERS

std::string const &Character::getName( void ) const
{
	return (this->_name);
}

int		Character::getHeld( void ) const
{
	return (this->_held);
}

int		Character::getHeldMax( void ) const
{
	return (this->_heldMax);
}


// METHODS

void	Character::equip( AMateria* m )
{
	int i = 0;
	for (i = 0; i < _heldMax && this->_inventory[i] != nullptr; i++);

	if (i < _heldMax)
	{
		this->_inventory[i] = m;
		this->_held += 1;
	}
	else
		std::cout << T_BHID "Our inventory cannot accomodate this Materia" T_N << std::endl;
	return ;
}


void	Character::unequip( int idx )
{
	// unequip method must NOT delete Materia
	if (idx >= 0 && idx < 4)
	{
		this->_inventory[idx] = nullptr;
		this->_held -= 1;
	}
	else
		std::cout << T_BHID "Idx given in unequip is currently not existant" T_N << std::endl;
	return ;
}


void	Character::use( int idx, ICharacter& target )
{
	if (idx >= 0 && idx < this->_heldMax) // Checking if idx is avalaible in our inventory
		this->_inventory[idx]->use(target); // pass target as parameter to the AMateria::use method
	else
		std::cout << T_BHID "Idx given in use is currently not existant" T_N << std::endl;
	return ;
}