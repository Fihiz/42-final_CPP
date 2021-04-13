/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:26:18 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 11:41:04 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include <iostream>

#include "AWeapon.hpp"

class PowerFist : public AWeapon	// Inherits from AWeapon, which is the "basic plan to follow" to define a Weapon
{
    public:
		// Coplien form -> By inheritance ?
		PowerFist( void );										// Default constructor
		PowerFist( PowerFist const &src );						// Copy constructor
		PowerFist &operator=( PowerFist const &rhs ); 			// Assignation operator overload
        virtual ~PowerFist( void );								// Destructor

		// Methods
		void 	attack( void ) const;							// Overriding pure virtual's mother function
};

#endif