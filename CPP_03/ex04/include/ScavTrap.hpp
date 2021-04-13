/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:16:38 by salome            #+#    #+#             */
/*   Updated: 2021/03/31 11:53:00 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public	ClapTrap
{
    public:
		// Coplien form : by inheritance ?
        ScavTrap( void );									// Default constructor
		ScavTrap( std::string const &name );				// Name constructor
		ScavTrap( ScavTrap const &src );					// Copy constructor
		ScavTrap &operator=( ScavTrap const &rhs ); 		// Assignation operator overload
        ~ScavTrap( void );									// Destructor

		// Own mandatory methods
		int				challengeNewcomer(std::string const & target);
		void			beRepaired( unsigned int amount );
};

#endif