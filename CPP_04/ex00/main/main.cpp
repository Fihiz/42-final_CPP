/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:09:21 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 11:32:55 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Sorcerer.hpp"
#include "../include/Peon.hpp"
#include "../include/Toad.hpp"

int		main()
{
	std::cout << T_R T_I "Avada Kedavra..." T_N << std::endl;
	
	// Testing the Default constructor, may not compile cause Default is in private
	// Sorcerer	crashtest;

	// Create a Sorcerer, testing the Name and Title constructor
	Sorcerer	robert("Robert", "The Magnificent");
	std::cout << robert; // Robert output with [<<] overload
	std::cout << std::endl;

	// Testing Assignation for sorcerer
	Sorcerer	equal("Vorldemort", "The Black Mage");
	equal = robert;
	std::cout << equal;
	std::cout << std::endl;

	// Testing Copy for sorcerer
	Sorcerer	copy(equal);
	std::cout << copy;
	std::cout << std::endl;

	std::cout << T_R T_I "It smells the moldu..." T_N << std::endl;
	// Create a Victim, testing the Name constructor
	Victim		moldu("Moldu");
	std::cout << moldu;
	std::cout << std::endl;

	// Polymorphing a moldu
	robert.polymorph(moldu);
	std::cout << std::endl;

	std::cout << T_R T_I "Great, another little victim..." T_N << std::endl;
	// Create a Peon, Victim's heir
	Peon		peon("Crab");
	std::cout << peon;
	std::cout << std::endl;

	// Polymorphing a peon
	robert.polymorph(peon);
	std::cout << std::endl;

	std::cout << T_R T_I "Oh, cute little princess in progress..." T_N << std::endl;
	// Create a Peon, Victim's heir
	Toad		toad("Golden Toad");
	std::cout << toad;
	std::cout << std::endl;

	// Polymorphing a toad
	robert.polymorph(toad);
	std::cout << std::endl;

	return (0);
}

// Testing : clang++ -Wall -Wextra -Werror src/*.cpp main/my_main.cpp