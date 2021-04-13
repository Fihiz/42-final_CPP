/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:47:29 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 11:39:04 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# define CLEAN "\e[1;1H\e[2J"
# define T_N "\033[00m"
# define T_WH "\033[1;37m"
# define T_I "\033[3m"
# define T_BO "\033[01"
# define T_Y "\033[00;33m"
# define T_GN "\033[00;32m"
# define T_GY "\033[03;90m"
# define T_CY "\033[00;36m"
# define T_R "\033[03;31m"
# define T_PU "\033[00;35m"
# define T_GYB "\033[01;90m"
# define T_B "\033[00;34m"
# define T_BB "\033[01;34m"
# define T_BHID "\033[2;34m"
# define T_GYHID "\033[2;34m"

#include <iostream>

/* Think to the ICoffee Maker example, 
** a Weapon can be owned by multiple type, but it has a precise behavior */

class	AWeapon
{
	protected:
		/* Attributes are allowed because I have concrete methods, 
		** but only derived objects can have them. */
		
		std::string		_name;
		int				_APcost;									// Action points cost
		int				_damage;									// Inflicted damage
		AWeapon( void );											// Default constructor


	public:
		// Coplien form
		AWeapon(std::string const & name, int apcost, int damage);	// Name constructor
		AWeapon( AWeapon const &src );								// Copy constructor
		AWeapon &operator=( AWeapon const &rhs ); 					// Assignation operator overload
		virtual ~AWeapon( void );									// Virtual Destructor
		
		/* As a guideline, any time you have a virtual function in a class, you should immediately 
		** add a virtual destructor (even if it does nothing). This way, you ensure against any surprises later. */
		
		// Getters
		std::string const	getName( void ) const;					// Concrete methods
		int					getAPCost( void ) const;
		int					getDamage( void ) const;
		
		// Methods
		virtual void 	attack( void ) const = 0;					// Pure virtual function
		
		/* That amounts to saying the method does not exist. My AWeapon is saying that in case of
		** inheritance, the derived object would have the attack behavior but AWeapon in itself
		** has no attack. */
};

#endif