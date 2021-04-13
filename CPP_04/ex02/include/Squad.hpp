/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:25:45 by salome            #+#    #+#             */
/*   Updated: 2021/04/10 14:45:03 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

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
#include <cstddef> // Is ok

#include "ISquad.hpp"

	/* Here I got a concrete class of the ISquad interface, 
	** this is why Squad class obviously inherits from ISquad.
	** Squad is a simple container of Space Marines, which 
	** we’ll use to correctly structure our army. */

class Squad : public ISquad
{
	/* I got concrete getters, so I obviously have attributes */
	private:
		int					_sum;								// Number of units currently in the squad
		ISpaceMarine**		_list;								// A pointer to the Nth unit (using a double I can point on it with a defined index)

	public:
		// Coplien form
		Squad( void );											// Default constructor
		Squad( Squad const &src );								// Copy constructor
		Squad &operator=( Squad const &rhs ); 					// Assignation operator overload, must use Deep Copy
		
		/* Depending upon the resources like dynamic memory held by the object, 
		** either we need to perform Shallow Copy or Deep Copy in order to create 
		** a replica of the object. In general, if the variables of an object have been
		** dynamically allocated then it is required to do a Deep Copy in order
		** to create a copy of the object. */
		
		~Squad( void );											// Destructor

		// Getters
		int 				getCount( void ) const;				// Returns the number of units currently in the squad
		ISpaceMarine* 		getUnit( int ) const;				// Returns a pointer to the Nth unit (beginning by 0)

		// Methods
		int 				push( ISpaceMarine* );				/* Adds the x unit to the end of the squad
																** and returns the number of units in the squad
																** after the operation */
};

#endif