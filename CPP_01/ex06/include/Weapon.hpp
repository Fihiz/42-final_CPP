/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:23:48 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 11:10:42 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# define CLEAN "\e[1;1H\e[2J"
# define T_N "\033[00m"
# define T_YB "\033[2;33m"
# define T_GNB "\033[01;32m"
# define T_GYB "\033[01;90m"
# define T_GY "\033[00;90m"
# define T_BB "\033[01;34m"
# define T_BHID "\033[2;34m"
# define T_GYHID "\033[2;34m"
# define T_CB "\033[01;36m"
# define T_RB "\033[01;31m"
# define T_R "\033[00;31m"

#include <iostream>
#include <sstream>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon( void ); // Default
		Weapon( std::string type ); // Initializor
		~Weapon();

		void	setType( std::string const &type );
		const std::string	&getType( void ) const; //Returns a const ref of type, remember a reference like an alias
};

#endif