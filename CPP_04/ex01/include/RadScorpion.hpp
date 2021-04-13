/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:42:46 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/11 11:45:30 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include <iostream>

#include "Enemy.hpp"

class RadScorpion : public Enemy	// Inherits from Enemy
{
    public:
		// Coplien form (-> By inheritance ?)
		RadScorpion( void );										// Default constructor
		RadScorpion( RadScorpion const &src );						// Copy constructor
		RadScorpion &operator=( RadScorpion const &rhs ); 			// Assignation operator overload
        virtual ~RadScorpion( void );								// Destructor
};

#endif