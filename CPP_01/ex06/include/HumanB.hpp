/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:23:39 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 11:14:16 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_bName;
		Weapon* _bWeapon; // I'll use a pointer cause reference can't be null

	public:
		HumanB( std::string name ); // Accessing directly to name ref variable and not a copy ?
		~HumanB( void );

		void	attack( void );
		void    setWeapon( Weapon& weapon);
};

#endif