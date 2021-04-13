/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:38:07 by salome            #+#    #+#             */
/*   Updated: 2021/04/02 10:40:18 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define CLEAN "\e[1;1H\e[2J"
# define T_N "\033[00m"
# define T_YB "\033[01;33m"
# define T_GNB "\033[01;32m"
# define T_GYB "\033[01;90m"
# define T_GY "\033[03;90m"
# define T_BB "\033[01;34m"
# define T_WH "\033[1;37m"
# define T_BHID "\033[2;34m"
# define T_GYHID "\033[2;34m"
# define T_CB "\033[01;36m"
# define T_RB "\033[01;31m"
# define T_RI "\033[03;31m"
# define T_PU "\033[01;35m"
# define T_I "\033[3m"

#include <iostream>

class ClapTrap
{
    protected:
		unsigned int    _hitPoints;
		unsigned int	_maxHitPoints;
		unsigned int	_energyPoints;
		unsigned int	_maxEnergyPoints;
		unsigned int	_level;
		std::string		_name;
		unsigned int	_meleeAttackDamage;
		unsigned int	_rangedAttackDamage;
		unsigned int	_armorDamageReduction;

    public:
		// Coplien form
        ClapTrap( void );									// Default constructor
		ClapTrap( std::string const &name );				// Name constructor
		ClapTrap( ClapTrap const &src );					// Copy constructor
		ClapTrap &operator=( ClapTrap const &rhs ); 		// Assignation operator overload
        ~ClapTrap( void );									// Destructor

		// Getters
		std::string		getName( void );
		unsigned int	getEnergyPoints( void );
		unsigned int	getHitPoints( void );
		unsigned int	getRangedAttackDamage( void );
		unsigned int	getMeleeAttackDamage( void );
		
		// Mandatory methods
		std::string		clapRandomAnnounce( int type );
		void			clapPresentation( void );
		// Common mandatory methods
		int				rangedAttack( std::string const & target );
		int				meleeAttack( std::string const & target );
		int				takeDamage( unsigned int amount );
};

#endif