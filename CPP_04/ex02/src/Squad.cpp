/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:25:41 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 12:06:00 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Squad.hpp"

// COPLIEN FORM

Squad::Squad( void ) : _sum(0), _list(nullptr)
{
	return ;
}

Squad::Squad( Squad const &src ): _sum(0), _list(nullptr)
{
	std::cout << T_GYHID "Squad Copy constructor called" T_N << std::endl;

	*this = src; // Calling assignation overload for copy
	return ;
}

Squad &Squad::operator=( Squad const &rhs )
{
	std::cout << T_GYHID "Squad Assignation operator called" T_N << std::endl;

	/* Deep copy process will allow me to create a copy of a Squad that 
	** contains units, giving a new separate address to its pointer,
	** so not using the same like in case of a shallow copy. */
	
	if (this == &rhs)
		return (*this);

	if (this->_list) // If there was any unit in the Squad before, they must be destroyed before being replaced for deep copy
	{
		for (int i = 0; i < this->_sum; i++)
			delete this->_list[i];
		delete this->_list;
		this->_list = nullptr; // To generate a new separate address
	}
	this->_sum = 0; // Restoring sum
	for (int i = 0; i < rhs.getCount(); i++)
		this->push(rhs.getUnit(i)->clone()); // Copying [getCount number] of units, pushing it by New into our list
	return (*this);
}

Squad::~Squad( void )
{
	// When a Squad is destroyed, the units inside are destroyed also, in order
	if (this->_list)
	{
		for (int i = 0; i < this->_sum; i++)
			delete this->_list[i];
		delete this->_list;
	}
	return ;
}


// GETTERS

int 	Squad::getCount( void ) const
{
	return (this->_sum);
}

ISpaceMarine* 		Squad::getUnit( int pos ) const
{		
	if (pos < 0 || pos >= this->_sum)
		return (nullptr); 		//  Null pointer in case of out-of-bounds index
	return (this->_list[pos]); 	// By using a double pointer, I can return a *ISpaceMarine[i]
}


// METHODS

int 				Squad::push( ISpaceMarine* newUnit )
{
	if (!newUnit)	// Checking if the newUnit is null
	{
		std::cout << T_GYB "Nothing changes for an old team, except if the unit is non-null..." T_N << std::endl;
		return (getCount());
	}
	if (this->_list)
	{
		for (int i = 0; i < this->_sum; i++)
			if (this->_list[i] == newUnit)  // Checking if the newUnit is already existant in the list
			{
				std::cout << T_GYB "You tried to push a new unit, but this fellow is already in our rank!" T_N << std::endl;
				return (this->getCount());
			}
	}

	ISpaceMarine **unlargedList = new ISpaceMarine*[this->_sum + 1]; // Generating a larger list (this->sum is 0 at the beginning)

	for (int i = 0; i < this->_sum; ++i)
		unlargedList[i] = this->_list[i]; // Filling the larger list by our previous units (if there is not, i = 0)
	
	unlargedList[this->_sum] = newUnit; // Adding the entering unit at the end of our new enlarged list

		delete[] this->_list; // Removing the old one
		this->_list = nullptr;
		this->_list = unlargedList; // List is now updating with the new entry

	return (++this->_sum); // +1 number of units in the squad
}