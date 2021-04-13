/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:37:50 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/11 12:34:54 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
# define FIRE_HPP

#include "AMateria.hpp"

// Inherits from AMateria, which is the "basic plan to follow" to define a Fire
class Fire : public AMateria
{
	public:
		// Coplien form
		Fire( void );
		Fire( Fire const &src );		
		Fire &operator=( Fire const &rhs );
		virtual ~Fire();

	// Methods
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif