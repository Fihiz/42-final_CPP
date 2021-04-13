/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:38:43 by salome            #+#    #+#             */
/*   Updated: 2021/04/02 10:48:19 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/FragTrap.hpp"
#include "include/ScavTrap.hpp"

int		main()
{
	srand (time(NULL));
	std::cout << T_WH "Let's have a look on our master, or should I say mother class, I mean the ClapTrap class !\n" T_N << std::endl;
	
	// One Mother
	ClapTrap robotMother;
	robotMother.clapPresentation();
	std::cout << T_GYB T_I "\"Hey there, I'm the robot mother. Let met create you two little robots..." << std::endl;
	std::cout << "Let's say a " << T_YB "FR4G-TP" << T_GY ", and a " << T_YB "SC4V-TP"<< T_GY ". They love to play fight together.\"" T_N << std::endl;
	std::cout << std::endl;

	// One Son
	FragTrap fragRobotSon("SO4P-PITT");
	fragRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"" << fragRobotSon.clapRandomAnnounce(0) << "\"" << T_N << std::endl;
	std::cout << std::endl;

	// One Son
	ScavTrap scavRobotSon("CL4P-PITT");
	scavRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"" << scavRobotSon.clapRandomAnnounce(0) << "\"" << T_N << std::endl;
	std::cout << std::endl;
	
	// Scav demonstration
	scavRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"Hey we look similar but I actually have my own speciality... CHALLEEEENGE.\"" T_N << std::endl;
	scavRobotSon.challengeNewcomer(fragRobotSon.getName());
	std::cout << std::endl;

	// Frag demonstration
	fragRobotSon.meleeAttack(scavRobotSon.getName());
	scavRobotSon.takeDamage(fragRobotSon.getMeleeAttackDamage());
	std::cout << std::endl;
	
	scavRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"I also can do it !\"" T_N << std::endl;
	scavRobotSon.meleeAttack(fragRobotSon.getName());
	fragRobotSon.takeDamage(scavRobotSon.getMeleeAttackDamage());
	std::cout << std::endl;
	
	fragRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"But you can't do that bro!\"" T_N << std::endl;
	fragRobotSon.vaulthunter_dot_exe(scavRobotSon.getName());
	scavRobotSon.takeDamage(fragRobotSon.getVaultAttackDamage());
	std::cout << std::endl;
	scavRobotSon.beRepaired(110);
	scavRobotSon.challengeNewcomer(fragRobotSon.getName());
	std::cout << std::endl;
	scavRobotSon.challengeNewcomer(fragRobotSon.getName());
	std::cout << std::endl;
	scavRobotSon.challengeNewcomer(fragRobotSon.getName());
	std::cout << std::endl;
	
	fragRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"" << scavRobotSon.clapRandomAnnounce(3) << "\"" << T_N << std::endl;
	fragRobotSon.vaulthunter_dot_exe(scavRobotSon.getName());
	scavRobotSon.takeDamage(fragRobotSon.getVaultAttackDamage());
	std::cout << std::endl;
	robotMother.clapPresentation();
	std::cout << T_GYB T_I "\"ENOUGH SONS! LET'S GO TO THE DESTRUCTORS IN FAMILY\"" << T_N << std::endl;

	return (0);
}