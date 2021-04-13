/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:34:41 by salome            #+#    #+#             */
/*   Updated: 2021/03/30 18:30:08 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScavTrap.hpp"

int		main()
{
	srand (time(NULL));

	// Intro
	ScavTrap	doorKeeper("SC4V-TP");
	doorKeeper.scavPresentation();
	std::cout << T_CB T_I "\"" << doorKeeper.scavRandomAnnounce(0) << "\"" << T_N << std::endl;
	std::cout << std::endl;

	FragTrap	traveller("CLAP-9000");
	traveller.fragPresentation();
	std::cout << T_CB T_I "\"" << traveller.fragRandomAnnounce(0) << "\"" << T_N << std::endl;
	std::cout << std::endl;

	// Doorkeeper demonstration
	doorKeeper.challengeNewcomer(traveller.getName());
	std::cout << std::endl;
	doorKeeper.challengeNewcomer(traveller.getName());
	std::cout << std::endl;
	doorKeeper.challengeNewcomer(traveller.getName());
	std::cout << std::endl;
	doorKeeper.beRepaired(10);
	std::cout << std::endl;

	// Both demonstration
	traveller.meleeAttack(doorKeeper.getName());
	std::cout << std::endl;
	
	doorKeeper.takeDamage(traveller.getMeleeAttackDamage());
	std::cout << std::endl;
	
	traveller.beRepaired(10);
	std::cout << std::endl;
	traveller.vaulthunter_dot_exe(doorKeeper.getName());
	std::cout << std::endl;
	
	doorKeeper.takeDamage(traveller.getVaultAttackDamage());
	std::cout << std::endl;
	doorKeeper.challengeNewcomer(traveller.getName());
	std::cout << std::endl;
	doorKeeper.challengeNewcomer(traveller.getName());
	std::cout << std::endl;
	
	traveller.rangedAttack(doorKeeper.getName());
	std::cout << std::endl;
	
	doorKeeper.takeDamage(traveller.getRangedAttackDamage());

	traveller.fragPresentation();
	std::cout << T_CB T_I "\"I am so impressed with myself!\"" << T_N << std::endl;
	std::cout << T_GY "But " << traveller.getName() << " didn't know the door was actually trapped and led to the destructor !" T_N << std::endl;
	std::cout << std::endl;

	return (0);
}