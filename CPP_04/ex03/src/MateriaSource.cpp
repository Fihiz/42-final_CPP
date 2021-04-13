/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 08:18:59 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 15:45:56 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

// COPLIEN FORM 

MateriaSource::MateriaSource( void ) : _sum(0), _sumMax(4)
{
	for (int i = 0; i < getSumMax(); i++)
		this->_inventory[i] = nullptr;
	return ;
}

MateriaSource::MateriaSource( MateriaSource const &src )
{
	*this = src;
	return ;
}

// While assigning a Materia to another, copying the type doesn’t make sense...
MateriaSource &MateriaSource::operator=( MateriaSource const &rhs )
{
	if (this == &rhs)
		return (*this);

	for (int i = 0; i < _sumMax; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = nullptr;
	}
	this->_sum = rhs._sum;
	this->_sumMax = rhs._sumMax;
	for (int i = 0; i < rhs.getSumMax(); i++)
		this->_inventory[i] = rhs._inventory[i]->clone();
	return (*this); // Returning a reference(&Sorcerer), so I dereference my pointer
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < getSumMax(); i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = nullptr;
	}
	return ;
}


// GETTERS

int MateriaSource::getSum( void ) const
{
	return(this->_sum);
}

int MateriaSource::getSumMax( void ) const
{
	return(this->_sumMax);
}


// METHODS

// learnMateria must copy the Materia passed as parameter, and store it in memory to be cloned later
void 	MateriaSource::learnMateria( AMateria* stone)
{
	if (this->_sum < this->_sumMax && stone)
	{
		this->_inventory[this->_sum] = stone;
		this->_sum += 1;
	}
	else
		std::cout << T_BHID "Our learning Materia capacity is full" T_N << std::endl;
	return ;
}

// return a new Materia, which will be a copy of the Materia (previously learned by the Source) which type equals the parameter
AMateria*	MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < this->_sumMax; i++)
		if (this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone()); // Generating a new instance
	std::cout << T_BHID << type << " Materia cannot be created" T_N << std::endl;
	return (nullptr); // If the type is unknown (so not already store in our Character's inventory), I return a null pointer
}