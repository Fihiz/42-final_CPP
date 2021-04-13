/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:58:39 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/10 14:55:40 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# define CLEAN "\e[1;1H\e[2J"
# define T_N "\033[00m"
# define T_WH "\033[1;37m"
# define T_I "\033[3m"
# define T_BO "\033[01"
# define T_Y "\033[00;33m"
# define T_CB "\033[01;36m"
# define T_GN "\033[00;32m"
# define T_GY "\033[03;90m"
# define T_CY "\033[00;36m"
# define T_R "\033[03;31m"
# define T_PU "\033[00;35m"
# define T_GYB "\033[01;90m"
# define T_B "\033[00;34m"
# define T_BB "\033[01;34m"
# define T_BHID "\033[2;34m"
# define T_GYHID "\033[2;34m"

#include <iostream>

class Enemy
{
    protected:
        int             _HP;
        std::string     _type;
        Enemy( void );                                  // Default constructor -> Putting in private
                                                        // To not be instantiated without any type or HP
    
    public:
        // Coplien form
        Enemy( int hp, std::string const & type );      // HP and Type constructor
        Enemy( Enemy const &src );						// Copy constructor
		Enemy &operator=( Enemy const &rhs ); 			// Assignation operator overload
        virtual ~Enemy( void );                         // Virtual Destructor
    
        // Getters
        std::string const       getType( void ) const;
        int                     getHP( void ) const;

        // Methods
        virtual void takeDamage( int );                     // To be overloaded
        void         enemyStatusBar( void );				// Additional function
};

#endif