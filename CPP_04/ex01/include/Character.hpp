/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:06:24 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/09 14:37:18 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
    private:
        std::string     _name;
        int             _AP;
		AWeapon			*_weapon; // A pointer to AWeapon representing the current weapon
        Character( void );										// Default constructor
                                                                // To not be instantiated without any name
    
    public:
		// Coplien form
        Character(std::string const & name);					// Name constructor
        Character( Character const &src );						// Copy constructor
		Character &operator=( Character const &rhs ); 			// Assignation operator overload
        ~Character(); // Virtual is not needed
    
    
        //Getters 
        std::string const	getName( void ) const;
        int					getAP( void ) const;
        AWeapon				*getWeapon( void ) const;
    
        // Methods
        void 				recoverAP( void );
        void 				equip( AWeapon* );
        void 				attack( Enemy* ); // Overload
        void				characterStatusBar( void );			// Additional function
};

// An overload to the [«] operator that inserts a character introduction into the parameter output stream
std::ostream &operator<<( std::ostream &o, const Character &rhs );

#endif