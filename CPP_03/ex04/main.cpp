/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:44:13 by salome            #+#    #+#             */
/*   Updated: 2021/04/01 20:27:42 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/FragTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/NinjaTrap.hpp"
#include "include/SuperTrap.hpp"

int		main()
{

	srand (time(NULL));
	
	// One Mother class became Grand Mother class
	ClapTrap robotMother;
	robotMother.clapPresentation();
	std::cout << T_GYB T_I "\"Hey there, I'm the robot mother, it is with great emotion that I announce today, that after 3 redundants exercices..." << std::endl;
	std::cout << "I have become grand mother class, by the power of VIRTUAL! You knew my dear " << T_YB "FR4G-TP" << T_GY ", " << T_YB "SC4V-TP";
	std::cout << T_GY ", and the youngest, " << T_YB "NINJ4-TP" T_GY << ".\nNow please let me introduce a super mix of Frag and Ninja, ";
	std::cout << "I mean... " << T_YB "SUP3R-TP." T_GY << "\"" T_N << std::endl;
	std::cout << std::endl;

	// One Little Son
	SuperTrap superRobotLittleSon("SUP3R-TP");
	superRobotLittleSon.clapPresentation();
	std::cout << T_GYB T_I "\"" << superRobotLittleSon.clapRandomAnnounce(0) << "\"" << T_N << std::endl;
	std::cout << std::endl;

	// Our Guinea Pig
	SuperTrap superGuineaPig("GUINE4P1G");
	superRobotLittleSon.clapPresentation();
	std::cout << T_GYB T_I "\" Hey there, I'am the Guinea Pig to show you the power of SUP3R-TP... \"" << T_N << std::endl;
	std::cout << std::endl;

	superRobotLittleSon.vaulthunter_dot_exe(superGuineaPig.getName());
	superGuineaPig.takeDamage(superRobotLittleSon.getVaultAttackDamage());
	std::cout << std::endl;

	superGuineaPig.clapPresentation();
	std::cout << T_GYB T_I "\" Hey! Let me beRpaired to continue the show... \"" << T_N << std::endl;
	superGuineaPig.beRepaired(65);
	superGuineaPig.meleeAttack(superRobotLittleSon.getName());
	superRobotLittleSon.takeDamage(superGuineaPig.getMeleeAttackDamage());
	std::cout << std::endl;

	superRobotLittleSon.ninjaShoebox(superRobotLittleSon);
	superRobotLittleSon.rangedAttack(superGuineaPig.getName());
	superGuineaPig.takeDamage(superRobotLittleSon.getRangedAttackDamage()); // Super has 5 damage reduction, as Frag does
	std::cout << std::endl;

	//	 One Son
	FragTrap fragRobotSon("FR4G-TP");
	fragRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"" << fragRobotSon.clapRandomAnnounce(0) << "\"" << T_N << std::endl;
	std::cout << std::endl;

	// One Son
	ScavTrap scavRobotSon("SCAV-TP");
	scavRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"" << scavRobotSon.clapRandomAnnounce(0) << "\"" << T_N << std::endl;
	std::cout << std::endl;

	// One Son
	NinjaTrap ninjaRobotSon("NINJ4-TP");
	ninjaRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"" << ninjaRobotSon.clapRandomAnnounce(0) << "\"" << T_N << std::endl;
	std::cout << std::endl;

	// Ninja
	ninjaRobotSon.ninjaShoebox(fragRobotSon);
	std::cout << std::endl;
	ninjaRobotSon.ninjaShoebox(scavRobotSon);
	std::cout << std::endl;

	// Frag
	fragRobotSon.meleeAttack(ninjaRobotSon.getName());
	ninjaRobotSon.takeDamage(fragRobotSon.getMeleeAttackDamage());
	std::cout << std::endl;

	// Scav
	scavRobotSon.rangedAttack(ninjaRobotSon.getName());
	ninjaRobotSon.takeDamage(scavRobotSon.getRangedAttackDamage());
	std::cout << std::endl;

	// Frag
	fragRobotSon.vaulthunter_dot_exe(ninjaRobotSon.getName());
	ninjaRobotSon.takeDamage(fragRobotSon.getVaultAttackDamage()); // Ninja does not have damage reduction, he's dead
	std::cout << std::endl;

	// Super
	superRobotLittleSon.vaulthunter_dot_exe(superGuineaPig.getName());
	superGuineaPig.takeDamage(superRobotLittleSon.getVaultAttackDamage());
	superRobotLittleSon.meleeAttack(superGuineaPig.getName());
	std::cout << std::endl;
	
	// Scav
	scavRobotSon.rangedAttack(superRobotLittleSon.getName());
	superRobotLittleSon.takeDamage(scavRobotSon.getRangedAttackDamage());
	scavRobotSon.challengeNewcomer(fragRobotSon.getName());
	std::cout << std::endl;

	// Grand Mother end's words
	robotMother.clapPresentation();
	std::cout << T_GYB T_I "\"All right guys ! I think everyone understood your super singularity." << std::endl;
	std::cout << "Even if SUP3R-TP seems the best, he does not have the eloquence of his helder, SC4V-TP.\n";
	std::cout << "Well, let's go to the destructors now. Sorry super guys, you'll have 3 ones, this is the price to be a diamond heir!\"" T_N << std::endl;
	std::cout << std::endl;

	return (0);
}