/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:45:07 by salome            #+#    #+#             */
/*   Updated: 2021/04/02 11:03:57 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap 
{
    public:
		// Coplien form : by inheritance ?
        SuperTrap( void );									// Default constructor
		SuperTrap( std::string const &name );				// Name constructor
		SuperTrap( SuperTrap const &src );					// Copy constructor
		SuperTrap &operator=( SuperTrap const &rhs ); 		// Assignation operator overload
        ~SuperTrap( void );									// Destructor

		// Own mandatory methods
		void			beRepaired( unsigned int amount );
		int				ninjaShoebox( SuperTrap &target );
};

#endif