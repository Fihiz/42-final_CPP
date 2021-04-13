/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:58:41 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/11 11:44:21 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Enemy.hpp"

// COPLIEN FORM

Enemy::Enemy( void )
{
	return ;
}

Enemy::Enemy( int hp, std::string const & type ) :
    _HP(hp),
	_type(type)
{
    return ;
}

Enemy::Enemy( Enemy const &src )
{
	std::cout << T_GYHID "Enemy Copy constructor called" T_N << std::endl;
	*this = src; // Calling assignation overload for copy
	std::cout << T_BB << getType() << ", has been created by copy!" T_N << std::endl;
	return ;
}

Enemy &Enemy::operator=( Enemy const &rhs )
{
	std::cout << T_GYHID "Enemy Assignation operator called" T_N << std::endl;
	this->_HP = rhs.getHP();
	this->_type = rhs.getType();
	return (*this); // Returning a reference(&Enemy), so I dereference my pointer
}

Enemy::~Enemy()
{
	return ;
}


// GETTERS

std::string	const	Enemy::getType( void ) const
{
	return (this->_type);
}

int					Enemy::getHP( void ) const
{
	return (this->_HP);
}


// METHODS

void	Enemy::enemyStatusBar( void )
{
	std::cout << T_GYB "ENEMY BAR < " T_BB << getType() << T_GYB << ", HP(" T_BB;
	std::cout << getHP()  << T_GYB ") > " T_N;
	return ;
}

void 	Enemy::takeDamage( int damage )
{
	// Damage protection
	if (damage < 0)
    {
        std::cout << T_GYB "Damage is negative." T_N << std::endl;
        damage = 0;
    }
    // HP protection
	if (this->_HP - damage <= 0)
    	damage = this->_HP; // Then returns 0
	this->_HP -= damage;
	return ;
}


