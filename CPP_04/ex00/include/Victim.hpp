/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:47:07 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 11:21:32 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# define CLEAN "\e[1;1H\e[2J"
# define T_N "\033[00m"
# define T_WH "\033[1;37m"
# define T_I "\033[3m"
# define T_BO "\033[01"
# define T_Y "\033[00;33m"
# define T_GN "\033[00;32m"
# define T_GY "\033[03;90m"
# define T_CY "\033[00;36m"
# define T_R "\033[00;31m"
# define T_PU "\033[00;35m"
# define T_GYB "\033[01;90m"
# define T_B "\033[00;34m"
# define T_BB "\033[01;34m"
# define T_BHID "\033[2;34m"
# define T_GYHID "\033[2;34m"

#include <iostream>

class Victim
{
    protected:														// Accessible by the object and its derived
		std::string	_name;
		Victim( void );												// Default constructor

    public:
		// Coplien form
		Victim( std::string const &name );							// Name constructor
		Victim( Victim const &src );								// Copy constructor
		Victim &operator=( Victim const &rhs ); 					// Assignation operator overload
        virtual ~Victim( void );									// Destructor
		
		/* Making base class destructor virtual guarantees that the object of derived class 
		** is destructed properly, i.e., both base class and derived class destructors are called. */

		// Getters
		std::string getName( void ) const;
		
		// Methods
		virtual void		getPolymorphed( void ) const;			// Virtual, to be overriden into Peon class
		
		/* As a guideline, any time you have a virtual function in a class, you should immediately 
		** add a virtual destructor (even if it does nothing). This way, you ensure against any surprises later. */
};

// Victim output stream overload
std::ostream &operator<<( std::ostream &o, const Victim &rhs );

#endif