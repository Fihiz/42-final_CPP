/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:18:51 by salome            #+#    #+#             */
/*   Updated: 2021/04/10 14:45:09 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

#include "ISpaceMarine.hpp"

	/* Interface class, that only has abstract methods (so doesn't have any attributes), 
	** has to be seen as a contract with the developper who is responsible 
	** for coding concrete classes. A kind of building plan to get a final
	** product with defined behaviors, but the plan itself/the interface 
	** has no interest to be implemented and functional. */

class ISquad // I is a convetion to notice that this interface is fully abstract
{
	public:
		virtual ~ISquad() {}
		virtual int getCount() const = 0;					// Pure methods
		virtual ISpaceMarine* getUnit( int ) const = 0;
		virtual int push( ISpaceMarine* ) = 0;
		
		/* It doesn't factor anything but only describe that any 
		** derived object of the ISquad will have these behaviors */
};

#endif