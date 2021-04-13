/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 07:37:13 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 12:35:14 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

// Inherits from AMateria, which is the "basic plan to follow" to define a Cure
class Ice : public AMateria
{
	public:
		// Coplien form
		Ice( void );
		Ice( Ice const &src );		
		Ice &operator=( Ice const &rhs );
		virtual ~Ice();

	// Methods
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif