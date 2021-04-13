/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:23:37 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 11:40:49 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include <iostream>

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon	// Inherits from AWeapon, which is the "basic plan to follow" to define a Weapon
{
    public:
		// Coplien form (-> By inheritance ?)
		PlasmaRifle( void );										// Default constructor
		PlasmaRifle( PlasmaRifle const &src );						// Copy constructor
		PlasmaRifle &operator=( PlasmaRifle const &rhs ); 			// Assignation operator overload
        virtual ~PlasmaRifle( void );								// Destructor

		// Methods
		void 	attack( void ) const;								// Overriding pure virtual's mother function
};

#endif