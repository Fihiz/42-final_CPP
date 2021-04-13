/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:06:09 by salome            #+#    #+#             */
/*   Updated: 2021/04/02 10:36:26 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "FragTrap.hpp"

class ScavTrap
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

    public:
		// Coplien form
        ScavTrap( void );									// Default constructor
		ScavTrap( std::string const &name );				// Name constructor
		ScavTrap( ScavTrap const &src );					// Copy constructor
		ScavTrap &operator=( ScavTrap const &rhs ); 		// Assignation operator overload
        ~ScavTrap( void );									// Destructor

		// Getters
		std::string		getName( void );
		unsigned int	getEnergyPoints( void );
		unsigned int	getHitPoints( void );
		unsigned int	getRangedAttackDamage( void );
		unsigned int	getMeleeAttackDamage( void );
		
		// Methods
		std::string		scavRandomAnnounce( int type );
		void			scavPresentation( void );
		// Mandatory methods
		int				rangedAttack( std::string const & target );
		int				meleeAttack( std::string const & target );
		int				takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );
		int				challengeNewcomer(std::string const & target);
};



#endif