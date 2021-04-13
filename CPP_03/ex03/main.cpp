/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:39:44 by salome            #+#    #+#             */
/*   Updated: 2021/03/31 15:51:45 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/FragTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/NinjaTrap.hpp"

int		main()
{
	srand (time(NULL));
	
	// One Mother
	ClapTrap robotMother;
	robotMother.clapPresentation();
	std::cout << T_GYB T_I "\"Hey there, I'm the robot mother. Let met create you three little robots..." << std::endl;
	std::cout << "Let's say a " << T_YB "FR4G-TP" << T_GY ", a " << T_YB "SC4V-TP"<< T_GY ", and the youngest, a " << T_YB "NINJ4-TP" T_GY << ".\"" T_N << std::endl;
	std::cout << std::endl;

	// One Son
	FragTrap fragRobotSon("ONE-TP");
	fragRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"" << fragRobotSon.clapRandomAnnounce(0) << "\"" << T_N << std::endl;
	std::cout << std::endl;

	// One Son
	ScavTrap scavRobotSon("TWO-TP");
	scavRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"" << scavRobotSon.clapRandomAnnounce(0) << "\"" << T_N << std::endl;
	std::cout << std::endl;


	// One Son
	NinjaTrap ninjaRobotSon("TR3-TP");
	ninjaRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"" << ninjaRobotSon.clapRandomAnnounce(0) << "\"" << T_N << std::endl;
	std::cout << std::endl;

	ninjaRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"COME ON BOYS, LET ME TEACH YOU THE DISSIMULATION ART\"" << T_N << std::endl;
	ninjaRobotSon.ninjaShoebox(fragRobotSon);
	std::cout << std::endl;
	ninjaRobotSon.ninjaShoebox(scavRobotSon);
	std::cout << std::endl;
	
	fragRobotSon.meleeAttack(ninjaRobotSon.getName());
	ninjaRobotSon.takeDamage(fragRobotSon.getMeleeAttackDamage());
	std::cout << std::endl;
	ninjaRobotSon.ninjaShoebox(ninjaRobotSon);
	std::cout << std::endl;
	ninjaRobotSon.ninjaShoebox(scavRobotSon);
	ninjaRobotSon.ninjaShoebox(fragRobotSon);
	std::cout << std::endl;

	fragRobotSon.clapPresentation();
	std::cout << T_GYB T_I "\"" << fragRobotSon.clapRandomAnnounce(4) << "\"" << T_N << std::endl;
	std::cout << std::endl;

	robotMother.clapPresentation();
	std::cout << T_GYB T_I "\"TIME TO GO HOME SONS! LET'S GO TO THE DESTRUCTORS IN FAMILY\"" << T_N << std::endl;
	return (0);
}