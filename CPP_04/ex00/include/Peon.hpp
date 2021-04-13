/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:46:55 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 11:22:48 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include <iostream>

#include "Victim.hpp"

class Peon : public	Victim	// A peon is a victim, he's obviously inherit from Victim
{
    private:
		Peon( void );											// Default constructor

    public:
		// Coplien form (-> By inheritance ?)
		Peon( std::string const &name );						// Name constructor
		Peon( Peon const &src );								// Copy constructor
		Peon &operator=( Peon const &rhs ); 					// Assignation operator overload
        virtual ~Peon( void );									// Destructor
		
		/* Deleting a derived class object using a pointer of base class type that has a 
		** non-virtual destructor results in undefined behavior. To correct this situation, 
		** the base class should be defined with a virtual destructor.
		** Need to see with new and delete case */
		
		// Methods
		void	getPolymorphed( void ) const;					// Overriden function, to have its own behavior/message
};

#endif