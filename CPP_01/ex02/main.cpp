/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:22:26 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 09:54:38 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"
#include "include/ZombieEvent.hpp"

int		main()
{
	ZombieEvent	zEvent; //Statically allocated, I'll need this instance in the same way during all my programm

	//First using constructor (my attributes are initialized)

	Zombie	*firstZombie = new Zombie("Runner", "Syrup", "Two legs"); 
	firstZombie->announce();
	std::cout << T_GYB "\nOH NO ! STRAIGHT IN THE HEAD, KILL HIM !" << std::endl;
	std::cout << "By [delete] function, zombie destructor will be called." T_N << std::endl;
	delete	firstZombie;

	//Second using zEvent.newZombie, only name will be uninitialized

	std::cout << T_GYB "We're good now. Wait... What ? Another one ? ";
	std::cout << "But he has neither intialized type nor member!" T_N << std::endl;
	Zombie	*secondZombie = zEvent.newZombie("Freeze"); //Dynamically allocated, I'll make born and die zombies during all my programm
	secondZombie->announce();
	std::cout << T_GYB "Let's call [delete] again !" T_N << std::endl;
	delete	secondZombie;

	//Third using zEvent.newZombie, initializing type and member before calling

	std::cout << T_GYB "Oh shit... Here we go again." T_N << std::endl;
	zEvent.setZombieType("Screamer");
	zEvent.setZombieRemainingMember("One hand, two feet");
	Zombie	*thirdZombie = zEvent.newZombie("Soup");
	thirdZombie->announce();
	std::cout << T_GYB "You know what to do: [delete]." T_N << std::endl;
	delete	thirdZombie;

	//Fourth using zEvent.zombieChump
	
	std::cout << T_GYB "Ok, never give up." T_N << std::endl;
	zEvent.setZombieType("Stalker");
	zEvent.setZombieRemainingMember("A chest");
	Zombie	*fourthZombie = zEvent.randomChump();
	std::cout << T_GYB "Call [delete] power." T_N << std::endl;
	delete	fourthZombie;

	std::cout << T_GYB "Let's get the hell out of here now, with the return(0),";
	std::cout << " zombieEvent will be destroyed.\nThus no other zombie will appear and we'll be safe !" << std::endl;
	return (0); //Static suff will automatically be deleted
}

// Testing : clang++ src/*.cpp main.cpp -o zombie
// Checking : valgrind --leak-check=full ./zombie