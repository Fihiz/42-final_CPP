/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:22:08 by salome            #+#    #+#             */
/*   Updated: 2021/03/31 15:34:43 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public	ClapTrap
{
    public:
		// Coplien form : by inheritance ?
        NinjaTrap( void );									// Default constructor
		NinjaTrap( std::string const &name );				// Name constructor
		NinjaTrap( NinjaTrap const &src );					// Copy constructor
		NinjaTrap &operator=( NinjaTrap const &rhs ); 		// Assignation operator overload
        ~NinjaTrap( void );									// Destructor

		// Own mandatory methods
		int				ninjaShoebox( ClapTrap &target ); //Let's see virtual later
		int				ninjaShoebox( FragTrap &target );
		int				ninjaShoebox( ScavTrap &target );
		int				ninjaShoebox( NinjaTrap &target );
		void			beRepaired( unsigned int amount );
};

#endif