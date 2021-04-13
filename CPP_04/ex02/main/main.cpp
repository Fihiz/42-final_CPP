/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:21:00 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 12:10:59 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Squad.hpp"
#include "../include/TacticalMarine.hpp"
#include "../include/AssaultTerminator.hpp"

int main()
{
	ISpaceMarine* bobMarine = new TacticalMarine;
	ISpaceMarine* crabMarine = new TacticalMarine;
	ISpaceMarine* flowMarine = new TacticalMarine;

	Squad* marineTeam = new Squad; // If I put ISquad, my concrete assignation and copy would'nt be found

	std::cout << std::endl;
	std::cout << T_PU "Let's form our first marine squad" T_N;
	// Pushing our marines in their squad container
	marineTeam->push(bobMarine);
	marineTeam->push(crabMarine);
	marineTeam->push(flowMarine);
	std::cout << std::endl;
	// Wrong cases
	// Bob is already existant in the squad
	marineTeam->push(bobMarine);
	// Crab also, is already existant in the squad
	marineTeam->push(crabMarine);
	// Sending a null unit
	marineTeam->push(nullptr);
	std::cout << std::endl;
	
	std::cout << T_BB "Hey! We're also there, let's form our terminator gang" T_N << std::endl;
	ISpaceMarine* jimTerminator = new AssaultTerminator;
	ISpaceMarine* bradTerminator = new AssaultTerminator;
	ISpaceMarine* haileyTerminator = new AssaultTerminator;
	ISpaceMarine* freddieTerminator = new AssaultTerminator;

	Squad* terminatorTeam = new Squad;
	
	std::cout << std::endl;
	// Pushing our terminators in their squad container
	terminatorTeam->push(jimTerminator);
	// Jim is already existant in the squad
	terminatorTeam->push(jimTerminator);
	terminatorTeam->push(bradTerminator);
	terminatorTeam->push(haileyTerminator);
	terminatorTeam->push(freddieTerminator);
	std::cout << std::endl;

	std::cout << T_PU "Let's start the marine copy parade" T_N << std::endl;
	for (int i = 0; i < marineTeam->getCount(); ++i)
	{
		std::cout <<  T_PU "And " << i << "..." T_N << std::endl;
		ISpaceMarine* paradeSquad = marineTeam->getUnit(i); // Assigning our current unit into a virgin SpaceMarine
		paradeSquad->battleCry();
		paradeSquad->rangedAttack();
		paradeSquad->meleeAttack();
		std::cout << std::endl;
	}

	std::cout << T_BB "We the terminators, we parade in person!" T_N << std::endl;
	for (int i = 0; i < terminatorTeam->getCount(); ++i)
	{
		std::cout <<  T_BB "And " << i << "..." T_N << std::endl;
		terminatorTeam->getUnit(i)->battleCry();
		terminatorTeam->getUnit(i)->rangedAttack();
		terminatorTeam->getUnit(i)->meleeAttack();
		std::cout << std::endl;
	}
	
	std::cout << T_BB "What if we assigned the marine team in the terminator squad ?" << std::endl;
	std::cout << "The terminators would be deleted to be replaced, having the marines behavior...\n" << T_N << std::endl;
	
	//terminatorTeam is now marineTeam, meaning the marine battleCry, rangedAttack, meleeAttack...
	*terminatorTeam = *marineTeam;				// Dereferencing to have the attributes access
	terminatorTeam->getUnit(0)->battleCry();
	terminatorTeam->getUnit(1)->rangedAttack();
	terminatorTeam->getUnit(2)->meleeAttack();
	
	// We have 3 marines in the terminator squads, getUnit(3) is null
	ISpaceMarine* isUnit = terminatorTeam->getUnit(3);
	if (isUnit)
		terminatorTeam->getUnit(3)->meleeAttack();
	else
		std::cout << T_BHID "There is no third terminator that became a marine dude, your pointer is null\n" T_N << std::endl;

	delete terminatorTeam; // Will destroy all its units, thanks to the squad destructor
	std::cout << std::endl;
	delete marineTeam;	// Is not correct, marineTeam has been assigned into terminator

	return (0);
}
