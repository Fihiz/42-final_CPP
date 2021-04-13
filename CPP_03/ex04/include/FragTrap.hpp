/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:50:24 by salome            #+#    #+#             */
/*   Updated: 2021/04/02 11:04:24 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/* Virtual inheritance is a C++ technique that ensures only one copy of 
** a base class's member variables are inherited by grandchild derived classes.
** Without virtual inheritance, if two classes B and C inherit from a class A, 
** and a class D inherits from both B and C, then D will contain two copies of 
** A's member variables: one via B, and one via C. These will be accessible 
** independently,using scope resolution. Instead, if classes B and C inherit 
** virtually from class A, then objects of class D will contain only one set of 
** the member variables from class A.*/

class FragTrap : virtual public	ClapTrap
{
    private:
		static const unsigned int	_vaultAttackDamage = 70;

    public:
		// Coplien form : by inheritance ?
        FragTrap( void );									// Default constructor
		FragTrap( int preset );								// Diamond constructor
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
