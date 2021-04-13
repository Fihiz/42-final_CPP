/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:23:09 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 11:13:30 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_aName;
		Weapon& _aWeapon; //I can use a reference cause all is currently initialized

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA( void );

		void	attack( void );
};

#endif