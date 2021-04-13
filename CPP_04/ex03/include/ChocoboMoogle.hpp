/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChocoboMoogle.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:38:25 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/11 12:35:20 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHOCOBOMOOGLE_HPP
# define CHOCOBOMOOGLE_HPP

#include "AMateria.hpp"

// Inherits from AMateria, which is the "basic plan to follow" to define a ChocoboMoogle
class ChocoboMoogle : public AMateria
{
	public:
		// Coplien form
		ChocoboMoogle( void );
		ChocoboMoogle( ChocoboMoogle const &src );		
		ChocoboMoogle &operator=( ChocoboMoogle const &rhs );
		virtual ~ChocoboMoogle();

	// Methods
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif