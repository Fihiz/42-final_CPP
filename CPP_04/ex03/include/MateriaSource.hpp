/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 08:10:24 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 12:38:54 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

// Inherits from IMateriaSource, which is the "interface to follow" to define a MateriaSource
class MateriaSource: public IMateriaSource
{
	private:
		int			_sum;
		int			_sumMax;
		AMateria 	*_inventory[4];

	public:
		// Coplien form
		MateriaSource( void );
		MateriaSource( MateriaSource const &src );		
		MateriaSource &operator=( MateriaSource const &rhs );
		virtual ~MateriaSource();

		// Getters
		int getSum( void ) const;
		int getSumMax( void ) const;

		// Methods
		void learnMateria( AMateria* );
		AMateria* createMateria( std::string const & type );


};

#endif