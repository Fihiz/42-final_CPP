/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:12:06 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 16:32:39 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

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
#include <iomanip>

class	Zombie
{
	private:
		std::string _zombieType;
		std::string	_zombieName;
		std::string _zombieRemainingMember;

	public:
		Zombie ( std::string const, std::string const, std::string const );
		~Zombie ( void );
		
		std::string getZombieName( void ) const;
		//void		setZombieName( std::string );

		std::string getZombieType( void ) const;
		//void		setZombieType( std::string );

		std::string getZombieRemainingMember( void ) const;
		//void		setZombieRemainingMember( std::string );

		std::string	advert( void );
		void	announce( void );
};

#endif