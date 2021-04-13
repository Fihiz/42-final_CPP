/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 23:20:41 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 15:57:20 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		Character( void );	// Default constructor -> Putting in private
                            // To not be instantiated without any name
		std::string _name;
		AMateria 	*_inventory[4];		// Inventory of 4 materia
		int			_held;
		int			_heldMax;
	
	public:
		// Coplien form
		Character( std::string const &name );
		Character( Character const &src );		
		Character &operator=( Character const &rhs );
		virtual ~Character( void );
	
	// Getters
		std::string const & getName( void ) const;
		int			getHeld( void ) const;
		int 		getHeldMax( void ) const;

	// Methods
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );
};

#endif