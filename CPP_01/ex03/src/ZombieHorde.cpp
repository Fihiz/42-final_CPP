/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:55:58 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 10:39:59 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int n ) : _zombieSum( n )
{
	std::cout << T_BB "ZombieHorde constructor called" T_N << std::endl;
	
	if (n < 1 || n > 100)
	{
		std::cout << T_RB "Well, well... The number for generating zombies is actually corrupted." << std::endl;
		std::cout << T_GYB "Let's settle this by default to 3, to consider a horde and so delete it safely !" T_N << std::endl;
		n = 3;
		this->_zombieSum = n;
	}
	this->_zombieHorde = new Zombie[this->_zombieSum]; //Allocating _zombieSum(n) Zombie objects

	std::cout << T_GYB "\nOh oh..." T_N << std::endl;
	std::string names[12] = {"Cypher", "Bloom", "Freeze", "Fara", "Flesh", "Hodor", 
							"Nihar", "Sandwich", "Cake", "Purple", "Dams", "Golden"};
	srand (time(NULL));

	int z = 0;
	while (z < this->_zombieSum)
	{
		this->_zombieHorde[z].setZombieType("Runner"); //Intentionnaly setting the same type and remaining memeber for hordes
		this->_zombieHorde[z].setZombieRemainingMember("Two legs and two harms");
		this->_zombieHorde[z].setZombieName(names[rand() % 12]);
		z++;
	}
	return ;
}

ZombieHorde::~ZombieHorde( void )
{
	std::cout << T_GYB "\nLet's kill these " << this->_zombieHorde[0].getZombieType() << " zombies !" T_N << std::endl;
	delete[] _zombieHorde; //Killing n zombies in one time, it calls my zombie destructor n times
	std::cout << T_BB "ZombieHorde destructor called" T_N << std::endl;
	return ;
}

void	ZombieHorde::announce( void  )
{
	int i = 0;
	while (i < this->_zombieSum)
	{
		this->_zombieHorde[i].announce();
		i++;
	}
}