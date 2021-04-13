/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:00:32 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 12:30:17 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define CLEAN "\e[1;1H\e[2J"
# define T_N "\033[00m"
# define T_WH "\033[1;37m"
# define T_I "\033[3m"
# define T_BO "\033[01"
# define T_Y "\033[00;33m"
# define T_GN "\033[00;32m"
# define T_GY "\033[03;90m"
# define T_CY "\033[00;36m"
# define T_R "\033[00;31m"
# define T_PU "\033[00;35m"
# define T_GYB "\033[01;90m"
# define T_B "\033[00;34m"
# define T_BB "\033[01;34m"
# define T_BHID "\033[2;34m"
# define T_GYHID "\033[2;34m"

#include <iostream>

#include "ICharacter.hpp"

class AMateria
{
	protected:
		AMateria( void );				// Default constructor -> Putting in protected
                                        // To not be instantiated without any type
		std::string		_type;
		unsigned int 	_xp;
	
	public:
		// Coplien form
		AMateria( std::string const & type );
		AMateria( AMateria const &src );
		AMateria &operator=( AMateria const &rhs );
		virtual ~AMateria();

	// Getters
		std::string const & getType( void ) const; 	// Returns the materia type
		unsigned int getXP( void ) const; 			// Returns the Materia's XP
	
	// Methods
		virtual AMateria* clone() const = 0;		// Pure virtual function
		virtual void use(ICharacter& target);
};

#endif