/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:28:12 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 12:26:08 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/TacticalMarine.hpp"

// COPLIEN FORM

TacticalMarine::TacticalMarine( void )
{
	std::cout << T_GY "Tactical Marine ready for battle!" T_N << std::endl;
	return ;
}

TacticalMarine::TacticalMarine( TacticalMarine const &src )
{
	std::cout << T_GYHID "TacticalMarine Copy ready for battle!" T_N << std::endl;
	*this = src;
	return ;
}

TacticalMarine &TacticalMarine::operator=( TacticalMarine const & )
{
	return (*this); // Returning a reference(&TacticalMarine), so I dereference my pointer
}

TacticalMarine::~TacticalMarine( void )
{
	std::cout << T_R "Aaargh..." T_N << std::endl;
	return ;
}


// METHODS

ISpaceMarine*	TacticalMarine::clone( void ) const // Returns a copy of the current object
{
	std::cout << T_R "Marine Clone" T_N << std::endl;
	return (new TacticalMarine(*this)); // Calling the constructor
}		

void TacticalMarine::battleCry( void ) const
{
	std::cout << T_GY "For the holy PLOT!" T_N << std::endl;
	return ;
}

void TacticalMarine::rangedAttack( void ) const
{
	std::cout << T_GY "* attacks with a bolter *" T_N << std::endl;
	return ;
}

void TacticalMarine::meleeAttack( void ) const
{
	std::cout << T_GY "* attacks with a chainsword *" T_N << std::endl;
	return ;
}