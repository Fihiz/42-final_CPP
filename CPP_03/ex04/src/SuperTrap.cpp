/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:45:10 by salome            #+#    #+#             */
/*   Updated: 2021/04/02 11:06:18 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SuperTrap.hpp"

/* ****************************** COPLIEN FORM ****************************** */

SuperTrap::SuperTrap( void ) : FragTrap(42), NinjaTrap(42)
{
    std::cout << T_BB "SuperTrap Default Constructor called" T_N << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_maxHitPoints = FragTrap::_maxHitPoints;
	this->_energyPoints = NinjaTrap::_energyPoints;
	this->_maxEnergyPoints = NinjaTrap::_maxEnergyPoints;
	this->_level = FragTrap::_level;
	this->_meleeAttackDamage = NinjaTrap::_meleeAttackDamage;
	this->_rangedAttackDamage = FragTrap::_rangedAttackDamage;
	this->_armorDamageReduction = FragTrap::_armorDamageReduction;
	//this->rangedAttack = FragTrap::rangedAttack();
	return ;
}

/* Polymorphic constructor, to get an entry with a name given as a param,
** calling int constructors from Frag and Ninja to not override our attributes,
** but initialize from either side what is needed from Frag and Ninja.
** Other solution would be that I call my ClapTrap constructor here,
** redfining all attributes in what I need...*/

SuperTrap::SuperTrap( std::string const &name ) : FragTrap(42), NinjaTrap(42)
{
    std::cout << T_BB "SuperTrap Name constructor called for " T_CB;
	
	this->_hitPoints = FragTrap::_hitPoints;
	this->_maxHitPoints = FragTrap::_maxHitPoints;
	this->_energyPoints = NinjaTrap::_energyPoints;
	this->_maxEnergyPoints = NinjaTrap::_maxEnergyPoints;
	this->_name = name;
	this->_level = FragTrap::_level;
	this->_meleeAttackDamage = NinjaTrap::_meleeAttackDamage;
	this->_rangedAttackDamage = FragTrap::_rangedAttackDamage;
	this->_armorDamageReduction = FragTrap::_armorDamageReduction;

	std::cout << getName() <<  T_BB ", he's settling his attributes and wants to loudly announce himself... _> " << std::endl;

	/* If I just called the default or name constructor of both Frag and Ninja classes,
	** all attributes would be, by order define in Frag, and then overriden in Ninja, 
	** so corrupted for Super class. With an int (or whatever, but not already define) constructor, 
	** I can initialize values I need from either side without risking corruption. */

	return ;
}

SuperTrap::SuperTrap( SuperTrap const &src )
{
    std::cout << T_BB "SuperTrap Copy Constructor called" T_N << std::endl;
	*this = src; // This make assignation called for copy
	std::cout << T_CB << getName() << T_BHID << " is now copied, and has the same initialized attributes." T_N << std::endl;
	return ;
}

SuperTrap &SuperTrap::operator=( SuperTrap const &rhs )
{
	ClapTrap::operator=(rhs); // Calling GrandMa, who contains all attributes
    std::cout << T_BB "SuperTrap Assignation operator overload called for " T_YB << getName() << T_N << std::endl;
	return (*this);	// To return a reference (&Fragtrap), I juste dereference my pointer
}

SuperTrap::~SuperTrap( void )
{
    std::cout << T_BB "SuperTrap Destructor called for... " T_CB << this->_name << T_BB " _> " << T_RI "\"";
	std::cout << clapRandomAnnounce(1) << "\"" << T_N << std::endl;
	return ;
}

/* *************************** FIGHT **************************** */

/* No need to redefine any methods, damage are already set in terms of super constructor
** So calling fight methods from ClapTrap will be applied depending of initialized attributed (damage...) */

void		SuperTrap::beRepaired( unsigned int amount )
{
	FragTrap::beRepaired(amount); // Taking health ninja function by choice
}

int			SuperTrap::ninjaShoebox( SuperTrap &target ) // Adding SuperTrap target case
{
	std::cout << T_GY "A ninja takes care of himself and his peers." T_N << std::endl;
	std::cout << T_GY "It costs 25 energy points for " << getName() << ". Best things are the most expensive." T_N << std::endl;
	if (this->_energyPoints >= 25)
		this->_energyPoints -= 25;
	else
	{
		clapPresentation();
		std::cout << T_CB "\"Crap... Don't have enough energy for taking care.\"" T_N;
		return (0);
	}
	clapPresentation();
	std::cout << T_GYB " heals " T_CB << target.getName();
	std::cout << T_GYB ", causing " << T_YB  << 20 << " points of health!" T_N << std::endl;
	target.beRepaired(20);
	return (1);
}