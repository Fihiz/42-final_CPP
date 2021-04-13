/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Toad.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:22:18 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 11:24:44 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOAD_HPP
# define TOAD_HPP

#include <iostream>

#include "Victim.hpp"

class Toad : public	Victim	// A toad is a victim, he's obviously inherit from Victim
{
    private:
		Toad( void );											// Default constructor

    public:
		// Coplien form
		Toad( std::string const &name );						// Name constructor
		Toad( Toad const &src );								// Copy constructor
		Toad &operator=( Toad const &rhs ); 					// Assignation operator overload
        virtual ~Toad( void );									// Destructor

		// Methods
		void	getPolymorphed( void ) const;					// Overriden function, to have its own behavior/message
};

#endif