/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:44:57 by salome            #+#    #+#             */
/*   Updated: 2021/04/11 11:56:30 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SwordSpaghetti.hpp"
#include "../include/PlasmaRifle.hpp"
#include "../include/PowerFist.hpp"
#include "../include/SuperMutant.hpp"
#include "../include/RadScorpion.hpp"
#include "../include/WaterZombie.hpp"
#include "../include/Character.hpp"

int		main()
{
	// Crashtest, this instantiation may not compile, AWeapon is abstract
	// AWeapon gun("Ak47", 20, 50);

	// One weapon
	AWeapon* plasma = new PlasmaRifle();

	// Another weapon
	AWeapon* power = new PowerFist();

	// Another weapon
	AWeapon* spaghetti = new SwordSpaghetti();


	// One character
	Character*	firstWarrior = new Character("Marcus");
	firstWarrior->equip(plasma);
	std::cout << *firstWarrior;
	std::cout << T_BB << firstWarrior->getName() << " says " << T_GY "\"I changed my mind, I'll take a Power Fist\"" T_N << std::endl;
	firstWarrior->equip(power);
	std::cout << *firstWarrior << std::endl;

	// Another character
	Character*	secondWarrior = new Character("Joshua Graham");
	std::cout << *secondWarrior;

	// One mutant enemy
	Enemy* mutant = new SuperMutant();
	mutant->enemyStatusBar(); // Additional function
	std::cout << std::endl;
	// Doesn't have any weapon so attack won't do anything
	secondWarrior->attack(mutant);
	std::cout << T_BB << secondWarrior->getName() << " says " << T_GY "\"Hey, I can't do anything, let's fight with a Plasma Rifle\"" T_N;
	secondWarrior->equip(plasma);
	std::cout << std::endl;
	std::cout << *secondWarrior << std::endl;
	std::cout << std::endl;
	firstWarrior->attack(mutant);
	mutant->enemyStatusBar();
	std::cout << std::endl;
	firstWarrior->attack(mutant);
	mutant->enemyStatusBar();
	std::cout << std::endl;
	// Checking negative damage
	mutant->takeDamage(-2);
	std::cout << std::endl;
	firstWarrior->attack(mutant);
	mutant->enemyStatusBar();
	std::cout << std::endl;
	firstWarrior->attack(mutant);
	std::cout << std::endl;

	// Another mutant enemy to test AP loss and recover
	Enemy* mut = new SuperMutant();
	mut->enemyStatusBar();
	std::cout << std::endl;
	firstWarrior->attack(mut);
	mut->enemyStatusBar();
	std::cout << std::endl;
	firstWarrior->attack(mut);
	firstWarrior->characterStatusBar();
	std::cout << T_GY "says \"Need some AP to kick enemies\"" T_N << std::endl;
	std::cout << std::endl;
	firstWarrior->recoverAP();
	firstWarrior->recoverAP();
	firstWarrior->recoverAP();
	firstWarrior->recoverAP();
	firstWarrior->recoverAP();
	firstWarrior->recoverAP();
	firstWarrior->characterStatusBar();
	std::cout << T_GY "says \"Ok... I tried to go above 40 AP. Well coded dude\"" T_N << std::endl;
	std::cout << std::endl;


	mut->enemyStatusBar();
	std::cout << T_GY "says \"Ahahahah... let me call a friend\"" T_N << std::endl;

	// One radscorpion enemy
	Enemy* scorpion = new RadScorpion();
	scorpion->enemyStatusBar();
	std::cout << T_GY "says \"All riiiiiiight!\"" T_N << std::endl;
	std::cout << std::endl;

	firstWarrior->characterStatusBar();
	std::cout << T_GY "says \"I got a friend too dear mutant, and we're gonna kill you\"" T_N << std::endl;
	secondWarrior->characterStatusBar();
	std::cout << T_GY "says \"Let's go boys\"" T_N << std::endl;
	scorpion->enemyStatusBar();
	std::cout << std::endl;
	secondWarrior->attack(scorpion);
	scorpion->enemyStatusBar();
	std::cout << std::endl;
	secondWarrior->attack(scorpion);
	scorpion->enemyStatusBar();
	std::cout << std::endl;
	secondWarrior->attack(scorpion);
	scorpion->enemyStatusBar();
	std::cout << std::endl;
	secondWarrior->attack(scorpion);
	std::cout << std::endl;

	secondWarrior->characterStatusBar();
	std::cout << std::endl;
	std::cout << T_GY "says \"It feels so good. Where is the mutant now ?\"" T_N << std::endl;
	mut->enemyStatusBar();
	std::cout << std::endl;
	secondWarrior->attack(mut);
	mut->enemyStatusBar();
	std::cout << std::endl;
	secondWarrior->attack(mut);
	mut->enemyStatusBar();
	std::cout << std::endl;
	secondWarrior->attack(mut);
	mut->enemyStatusBar();
	std::cout << std::endl;
	secondWarrior->attack(mut);
	secondWarrior->characterStatusBar();
	std::cout << T_GY "says \"Shit. Not enouh AP. I let you finish the job " << firstWarrior->getName() << "\"" T_N << std::endl;
	std::cout << std::endl;

	firstWarrior->characterStatusBar();
	std::cout << T_GY "says \"No worries boy, let me draw the spaghetti sword for the final\"" T_N << std::endl;
	std::cout << std::endl;
	firstWarrior->equip(spaghetti);
	std::cout << *firstWarrior << std::endl;

	mut->enemyStatusBar();
	std::cout << std::endl;
	firstWarrior->attack(mut);
	mut->enemyStatusBar();
	std::cout << std::endl;
	firstWarrior->attack(mut);
	mut->enemyStatusBar();
	std::cout << std::endl;
	firstWarrior->attack(mut);
	std::cout << std::endl;
	firstWarrior->characterStatusBar();
	std::cout << T_GY "says \"Last push, final push\"" T_N << std::endl;
	mut->enemyStatusBar();
	std::cout << std::endl;
	firstWarrior->attack(mut);
	std::cout << std::endl;


	Enemy* zombie = new WaterZombie();
	zombie->enemyStatusBar();
	std::cout << T_GY "says \"Ahahah, you thought there was only two enemy types ?\"" T_N << std::endl;
	std::cout << std::endl;
	firstWarrior->attack(zombie);
	zombie->enemyStatusBar();
	std::cout << std::endl;
	firstWarrior->attack(zombie);
	zombie->enemyStatusBar();
	std::cout << std::endl;
	firstWarrior->attack(zombie);
	std::cout << std::endl;


	firstWarrior->characterStatusBar();
	std::cout << T_GY "says \"All right, we did it. Let's get out of here\"" T_N << std::endl;
	secondWarrior->characterStatusBar();
	std::cout << T_GY "says \"'Was easy\"" T_N << std::endl;

	
	delete firstWarrior;
	delete secondWarrior;
	delete plasma;
	delete power;
	delete spaghetti;
	return (0);
}