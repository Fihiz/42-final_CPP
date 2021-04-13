/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:12:19 by salome            #+#    #+#             */
/*   Updated: 2021/04/07 11:49:41 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PlasmaRifle.hpp"
#include "../include/PowerFist.hpp"
#include "../include/SuperMutant.hpp"
#include "../include/RadScorpion.hpp"
#include "../include/Character.hpp"

int main()
{
	Character* moi = new Character("moi");
	std::cout << *moi;
	
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	
	moi->equip(pr);
	std::cout << *moi;
	moi->equip(pf);
	moi->attack(b);
	std::cout << *moi;
	moi->equip(pr);
	std::cout << *moi;
	moi->attack(b);
	std::cout << *moi;
	moi->attack(b);
	std::cout << *moi;

	delete moi;
	delete pr;
	delete pf;
	
	return 0;
}