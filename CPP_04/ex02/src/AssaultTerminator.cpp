/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:39:14 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 12:25:42 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AssaultTerminator.hpp"

// COPLIEN FORM

AssaultTerminator::AssaultTerminator( void )
{
	std::cout << T_B "* teleports from space *" T_N << std::endl;
	return ;
}

AssaultTerminator::AssaultTerminator( AssaultTerminator const &src )
{
	std::cout << T_GYHID "* teleports copy from space *" T_N << std::endl;
	*this = src;
	return ;
}

AssaultTerminator &AssaultTerminator::operator=( AssaultTerminator const & )
{
	return (*this); // Returning a reference(&AssaultTerminator), so I dereference my pointer
}

AssaultTerminator::~AssaultTerminator( void )
{
	std::cout << T_R "I’ll be back..." T_N << std::endl;
	return ;
}


// METHODS

ISpaceMarine*	AssaultTerminator::clone( void ) const // Returns a copy of the current object
{
	std::cout << T_R "Terminator Clone" T_N << std::endl;
	return (new AssaultTerminator(*this)); // Calling the copy constructor
}		

void AssaultTerminator::battleCry( void ) const
{
	std::cout << T_GY "This code is unclean. PURIFY IT!" T_N << std::endl;
	return ;
}

void AssaultTerminator::rangedAttack( void ) const
{
	std::cout << T_GY "* does nothing *" T_N << std::endl;
	return ;
}

void AssaultTerminator::meleeAttack( void ) const
{
	std::cout << T_GY "* attacks with chainfists *" T_N << std::endl;
	return ;
}