/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WaterZombie.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:50:45 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/11 11:45:38 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WATERZOMBIE_HPP
# define WATERZOMBIE_HPP

#include <iostream>

#include "Enemy.hpp"

class WaterZombie : public Enemy	// Inherits from Enemy
{
    public:
		// Coplien form (-> By inheritance ?)
		WaterZombie( void );										// Default constructor
		WaterZombie( WaterZombie const &src );						// Copy constructor
		WaterZombie &operator=( WaterZombie const &rhs ); 			// Assignation operator overload
        virtual ~WaterZombie( void );								// Destructor
};

#endif