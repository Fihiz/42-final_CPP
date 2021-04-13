/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:47:04 by salome            #+#    #+#             */
/*   Updated: 2021/04/05 11:03:07 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>

#include "Victim.hpp"

class Sorcerer
{
    private:
		std::string	_name;
		std::string	_title;

		// To forbid my default constructor, I can put it in private or either put it in public but not implement it
		Sorcerer( void );												// Default constructor

    public:
		// Coplien form
		// Default constructor is in private
		Sorcerer( std::string const &name, std::string const &type );	// Name and Title constructor
		Sorcerer( Sorcerer const &src );								// Copy constructor
		Sorcerer &operator=( Sorcerer const &rhs ); 					// Assignation operator overload
        ~Sorcerer( void );												// Destructor

		// Getters
		std::string getName( void ) const;
		std::string getTitle( void ) const;
		std::string	getIdentity( void ) const;
		
		// Methods
		void		polymorph( Victim const & ) const;
};

// Sorcerer output stream overload
std::ostream &operator<<( std::ostream &o, const Sorcerer &rhs );

#endif