/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:56:10 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 10:43:20 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class	ZombieHorde
{
	private:
		int		_zombieSum;
		Zombie	*_zombieHorde;

	public:
		ZombieHorde ( int n );
		~ZombieHorde ( void );

		void	announce( void );
};

#endif