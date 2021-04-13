/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:22:46 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/11 15:55:24 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/Fire.hpp"
#include "../include/ChocoboMoogle.hpp"
#include "../include/Character.hpp"

int main()
{
  std::cout << T_GY "Let's begin the [final] fantasy...\n" T_N << std::endl;
  
  IMateriaSource *src = new MateriaSource();

  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  src->learnMateria(new Fire());
  src->learnMateria(new ChocoboMoogle());
  
  AMateria*  anotherIce = new Ice;
  // Testing inventory's limit
  src->learnMateria(anotherIce); // Is not stored into our Materia Source, need to be deleted
  src->learnMateria(anotherIce);
  src->learnMateria(anotherIce);
  delete anotherIce;
  std::cout << std::endl;

  // Creating characters
  Character* me = new Character("me");
  Character* cloud = new Character("Cloud");


  // Generating our previous learnt stones
  AMateria*   oneIce;
  AMateria*   oneCure;
  AMateria*   oneFire;
  AMateria*   oneChocoboMoogle;

	// Testing equip
  oneIce = src->createMateria("ice");
  me->equip(oneIce);
  oneCure = src->createMateria("cure");
  me->equip(oneCure);
  oneFire = src->createMateria("fire");
  me->equip(oneFire);
  oneChocoboMoogle = src->createMateria("chocobo & moogle");
  me->equip(oneChocoboMoogle);
  
  // Unknown Materia
  AMateria* wrongFire = src->createMateria("fiire");
  me->equip(wrongFire);
  // Full inventory
  AMateria* tooCure = src->createMateria("cure");
  me->equip(tooCure);
  std::cout << std::endl;
  delete tooCure;

  /* 0 = ice
	** 1 = cure
	** 2 = fire
	** 3 = chocobo & moogle */
  
  // Using materia
	me->use(-1, *cloud);  //Wrong index for use
  std::cout << std::endl;
	me->use(0, *cloud);
	std::cout << T_BB "oneIce's xp : " T_N << oneIce->getXP() << std::endl << std::endl;
	while (oneCure->getXP() < 30)
	me->use(1, *cloud);
	std::cout << T_BB "oneCure's xp : " T_N << oneCure->getXP() << std::endl << std::endl;
	me->use(2, *cloud);
	std::cout << T_BB "oneFire's xp : " T_N << oneFire->getXP() << std::endl << std::endl;
	// Let's xp to 100 for Chocobo & Moogle materia
	while (oneChocoboMoogle->getXP() < 60)
	me->use(3, *cloud);
	std::cout << T_BB "oneChocoboMoogle's xp : " T_N << oneChocoboMoogle->getXP() << std::endl;
	//Wrong index for use
	me->use(4, *cloud);
	std::cout << std::endl;

  // Assignation
  AMateria *twoIce;
  twoIce = src->createMateria("ice");

  std::cout << T_BB "Cloud held: " << cloud->getHeld() << T_N << std::endl;
  cloud->equip(twoIce);
  std::cout << T_BB "Cloud held: " << cloud->getHeld() << T_N << std::endl;
  cloud->unequip(0);
  cloud->unequip(5);
  std::cout << T_BB "Cloud held: " << cloud->getHeld() << T_N << std::endl;
  cloud->equip(twoIce);
  std::cout << T_BB "Cloud held: " << cloud->getHeld() << T_N << std::endl;
  *cloud = *me; // twoIce will be deleted by the assignation (deep copy)
  std::cout << T_N << std::endl;

  // Copy
  Character *tiff(cloud);
  std::cout << T_BB "Me held: " << me->getHeld() << T_N << std::endl;
  std::cout << T_BB "Cloud held: " << cloud->getHeld() << T_N << std::endl;
  std::cout << T_BB "Tiff held: " << tiff->getHeld() << T_N << std::endl;
  

  Character* oneTarget = new Character("Sephiroth");
  Character* twoTarget = new Character("Bubble");
  me->use(0, *oneTarget);
  tiff->use(1, *twoTarget);
  cloud->use(4, *oneTarget);
  cloud->use(3, *oneTarget);

  IMateriaSource *src2 = src; // Now I can delete src by src2

  delete me;
  delete src2;
  delete cloud;
  delete oneTarget;
  delete twoTarget;
  return (0);
}