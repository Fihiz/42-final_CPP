/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:39:17 by salome            #+#    #+#             */
/*   Updated: 2021/04/10 14:46:05 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

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

#include "ISpaceMarine.hpp"

/* Here I got a concrete class of the ISpaceMarine interface, 
** this is why AssaultTerminator class obviously inherits from ISpaceMarine. */

class AssaultTerminator : public ISpaceMarine
{
	public:
		// Coplien form
		AssaultTerminator( void );													// Default constructor
		AssaultTerminator( AssaultTerminator const &src );							// Copy constructor
		AssaultTerminator &operator=( AssaultTerminator const &rhs ); 				// Assignation operator overload
		~AssaultTerminator( void );													// Destructor

		// Methods
		virtual ISpaceMarine* clone( void ) const;		// Returns a copy of the current object
		virtual void battleCry( void ) const;
		virtual void rangedAttack( void ) const;
		virtual void meleeAttack( void ) const;
};

#endif