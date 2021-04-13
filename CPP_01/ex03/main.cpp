/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:54:51 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 10:36:26 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/ZombieHorde.hpp"

int		main()
{
	// Calling with a correct val
	ZombieHorde instHorde(7);
	instHorde.announce();

	// Calling with a wrong val
	ZombieHorde instHordeTwo(-15);
	instHordeTwo.announce();

	return (0); // All zombies are deleted in one time by ZombieHordeDestructor
}