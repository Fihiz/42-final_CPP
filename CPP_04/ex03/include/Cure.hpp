/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 07:37:08 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 12:35:02 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

// Inherits from AMateria, which is the "basic plan to follow" to define a Cure
class Cure : public AMateria
{
	public:
		// Coplien form
		Cure( void );
		Cure( Cure const &src );		
		Cure &operator=( Cure const &rhs );
		virtual ~Cure();

	// Methods
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif