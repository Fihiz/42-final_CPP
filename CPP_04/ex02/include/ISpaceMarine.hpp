/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:29:04 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 12:01:42 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

#include <iostream>

	/* Interface class, that only has abstract methods (so doesn't have any attributes), 
	** has to be seen as a contract with the developper who is responsible 
	** for coding concrete classes. A kind of building plan to get a final
	** product with defined behaviors, but the plan itself/the interface 
	** has no interest to be implemented and functional. */

class ISpaceMarine // I is a convetion to notice that this interface is fully abstract
{
	public:
		virtual ~ISpaceMarine( void ) {}
		virtual ISpaceMarine* clone( void ) const = 0;		// Returns a copy of the current object
		virtual void battleCry( void ) const = 0;
		virtual void rangedAttack( void ) const = 0;
		virtual void meleeAttack( void ) const = 0;

		/* It doesn't factor anything but only describe that any 
		** derived object of the ISquad will have these behaviors */
};

#endif