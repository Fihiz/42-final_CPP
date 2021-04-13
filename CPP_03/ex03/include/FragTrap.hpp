/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:50:24 by salome            #+#    #+#             */
/*   Updated: 2021/03/31 11:53:05 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public	ClapTrap
{
    private:
		static const unsigned int	_vaultAttackDamage = 70;

    public:
		// Coplien form : by inheritance ?
        FragTrap( void );									// Default constructor
		FragTrap( std::string const &name );				// Name constructor
		FragTrap( FragTrap const &src );					// Copy constructor
		FragTrap &operator=( FragTrap const &rhs ); 		// Assignation operator overload
        ~FragTrap( void );									// Destructor

		// Getters
		unsigned int	getVaultAttackDamage( void );
		// Own mandatory methods
		int				vaulthunter_dot_exe(std::string const & target);
		void			beRepaired( unsigned int amount );
};

#endif
