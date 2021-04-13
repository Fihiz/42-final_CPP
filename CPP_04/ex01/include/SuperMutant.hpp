/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:29:52 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/11 11:45:21 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include <iostream>

#include "Enemy.hpp"

class SuperMutant : public Enemy	// Inherits from Enemy
{
    public:
		// Coplien form (-> By inheritance ?)
		SuperMutant( void );										// Default constructor
		SuperMutant( SuperMutant const &src );						// Copy constructor
		SuperMutant &operator=( SuperMutant const &rhs ); 			// Assignation operator overload
        virtual ~SuperMutant( void );								// Destructor

		// Methods
        void        takeDamage( int );
};

#endif