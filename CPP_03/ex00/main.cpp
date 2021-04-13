/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:07:00 by salome            #+#    #+#             */
/*   Updated: 2021/03/30 16:00:31 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int		main()
{
	srand (time(NULL));
	int	who_wins = 0;
	int	fight = 1;

	// Intro
	FragTrap	*firstRobot = new FragTrap("CU5T-TP");
	firstRobot->fragPresentation();
	std::cout << T_CB T_I "\"" << firstRobot->fragRandomAnnounce(0) << "\"" << T_N << std::endl;

	FragTrap	*secondRobot = new FragTrap("B4R-BOT");
	secondRobot->fragPresentation();
	std::cout << T_CB T_I "\"" << secondRobot->fragRandomAnnounce(0) << "\"" << T_N << std::endl;
	std::cout << std::endl;
	

	// Fight invitation
	secondRobot->fragPresentation();
	std::cout <<  T_CB T_I "\"You wanna fight with me?! Put 'em up!.. Put 'em up?\"" T_N<< std::endl;
	firstRobot->fragPresentation();
	std::cout << T_CB T_I "\"Now? But I... I just... okay...\"" T_N << std::endl;
	std::cout << std::endl;


	// Fighttttt
	while (fight)
	{
		if (secondRobot->rangedAttack(firstRobot->getName()))
		if (firstRobot->takeDamage(firstRobot->getRangedAttackDamage()))
		{
			delete firstRobot;
			who_wins = 2;
			break ;
		}
		std::cout << std::endl;

		if (firstRobot->meleeAttack(secondRobot->getName()))
			if (secondRobot->takeDamage(secondRobot->getMeleeAttackDamage()))
			{
				delete secondRobot;
				who_wins = 1;
				break ;
			}
		std::cout << std::endl;

		if (secondRobot->vaulthunter_dot_exe(firstRobot->getName()))
			if (firstRobot->takeDamage(firstRobot->getVaultAttackDamage()))
			{
				delete firstRobot;
				who_wins = 2;
				break ;
			}
		std::cout << std::endl;

		firstRobot->beRepaired(10);
		std::cout << std::endl;

		if (secondRobot->meleeAttack(firstRobot->getName()))
			if (firstRobot->takeDamage(firstRobot->getMeleeAttackDamage()))
			{
				delete firstRobot;
				who_wins = 2;
				break ;
			}
		std::cout << std::endl;

		secondRobot->beRepaired(20);
		std::cout << std::endl;
		secondRobot->beRepaired(90);
		std::cout << std::endl;

		if (firstRobot->vaulthunter_dot_exe(secondRobot->getName()))
			if (secondRobot->takeDamage(secondRobot->getVaultAttackDamage()))
			{
				delete secondRobot;
				who_wins = 1;
				break ;
			}
		std::cout << std::endl;
		
		if (secondRobot->rangedAttack(firstRobot->getName()))
			if (firstRobot->takeDamage(firstRobot->getRangedAttackDamage()))
			{
				delete firstRobot;
				who_wins = 2;
				break ;
			}
		std::cout << std::endl;
	}

	// Farewells
	if (who_wins == 1)
	{
		std::cout << T_PU << firstRobot->getName() << " won!" T_N << std::endl;
		firstRobot->fragPresentation();
		std::cout << T_CB T_I "\"" << firstRobot->fragRandomAnnounce(2) << "\"" << T_N << std::endl;
		delete firstRobot;
	}
	else if (who_wins == 2)
	{
		std::cout << T_PU << secondRobot->getName() << " won!" T_N << std::endl;
		secondRobot->fragPresentation();
		std::cout << T_CB T_I "\"" << firstRobot->fragRandomAnnounce(3) << "\"" << T_N << std::endl;
		delete secondRobot;
	}
	else if (who_wins == 0)
	{
		firstRobot->fragPresentation();
		std::cout << T_CB T_I "\"" << firstRobot->fragRandomAnnounce(4) << "\"" << T_N << std::endl;
		delete firstRobot;
		delete secondRobot;
	}
	return (0);
}