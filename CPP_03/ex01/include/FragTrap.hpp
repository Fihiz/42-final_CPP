/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:27:03 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/30 16:50:15 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

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

class FragTrap
{
    private:
		unsigned int    _hitPoints;
		unsigned int	_maxHitPoints;
		unsigned int	_energyPoints;
		unsigned int	_maxEnergyPoints;
		unsigned int	_level;
		std::string		_name;
		unsigned int	_meleeAttackDamage;
		unsigned int	_rangedAttackDamage;
		unsigned int	_armorDamageReduction;

		static const unsigned int	_vaultAttackDamage = 70;

    public:
		// Coplien form
        FragTrap( void );									// Default constructor
		FragTrap( std::string const &name );				// Name constructor
		FragTrap( FragTrap const &src );					// Copy constructor
		FragTrap &operator=( FragTrap const &rhs ); 		// Assignation operator overload
        ~FragTrap( void );									// Destructor

		// Getters
		std::string		getName( void );
		unsigned int	getEnergyPoints( void );
		unsigned int	getHitPoints( void );
		unsigned int	getRangedAttackDamage( void );
		unsigned int	getMeleeAttackDamage( void );
		unsigned int	getVaultAttackDamage( void );
		
		// Methods
		std::string		fragRandomAnnounce( int type );
		void			fragPresentation( void );
		// Mandatory methods
		int				rangedAttack( std::string const & target );
		int				meleeAttack( std::string const & target );
		int				takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );
		int				vaulthunter_dot_exe(std::string const & target);
};

#endif
