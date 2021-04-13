/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SwordSpaghetti.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:19:02 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/11 11:41:13 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWORDSPAGHETTI_HPP
# define SWORDSPAGHETTI_HPP

#include <iostream>

#include "AWeapon.hpp"

class SwordSpaghetti : public AWeapon	// Inherits from AWeapon, which is the "basic plan to follow" to define a Weapon
{
    public:
		// Coplien form -> By inheritance ?
		SwordSpaghetti( void );										    // Default constructor
		SwordSpaghetti( SwordSpaghetti const &src );					// Copy constructor
		SwordSpaghetti &operator=( SwordSpaghetti const &rhs ); 		// Assignation operator overload
        virtual ~SwordSpaghetti( void );								// Destructor

		// Methods
		void 	attack( void ) const;									// Overriding pure virtual's mother function
};

#endif