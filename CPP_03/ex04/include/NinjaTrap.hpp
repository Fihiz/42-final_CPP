/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:22:08 by salome            #+#    #+#             */
/*   Updated: 2021/04/01 16:12:48 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/* Virtual inheritance is a C++ technique that ensures only one copy of 
** a base class's member variables are inherited by grandchild derived classes. 
** Without virtual inheritance, if two classes B and C inherit from a class A, 
** and a class D inherits from both B and C, then D will contain two copies of 
** A's member variables: one via B, and one via C. These will be accessible 
** independently,using scope resolution. Instead, if classes B and C inherit 
** virtually from class A, then objects of class D will contain only one set of 
** the member variables from class A.*/

class NinjaTrap : virtual public ClapTrap
{
    public:
		// Coplien form : by inheritance ?
        NinjaTrap( void );									// Default constructor
		NinjaTrap( int preset );							// Diamond constructor
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