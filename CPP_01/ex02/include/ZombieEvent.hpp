/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:54:17 by salome            #+#    #+#             */
/*   Updated: 2021/03/20 16:51:58 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class	ZombieEvent
{
	private:
		std::string _type;
		std::string _remainingMember;

	public:
		ZombieEvent ( void );
		~ZombieEvent (void );

		void		setZombieType ( std::string );
		void		setZombieRemainingMember( std::string );

		Zombie		*newZombie ( std::string name );
		Zombie		*randomChump ( void );
};

#endif