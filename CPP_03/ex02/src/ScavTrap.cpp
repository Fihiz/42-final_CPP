/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:16:21 by salome            #+#    #+#             */
/*   Updated: 2021/04/02 10:47:07 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

/* ****************************** COPLIEN FORM ****************************** */

ScavTrap::ScavTrap( void )
{
    std::cout << T_BB "ScavTrap Default Constructor called" T_N << std::endl;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;
	return ;
}

/* Polymorphic constructor, to get an entry with a name given as a parameter */

ScavTrap::ScavTrap( std::string const &name )
{
    std::cout << T_BB "ScavTrap Name constructor called for " T_CB;
	this->_name = name;
	std::cout << getName() <<  T_BB ", he's settling his attributes and wants to appear... _> " << std::endl;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const &src )
{
    std::cout << T_BB "ScavTrap Copy Constructor called" T_N << std::endl;
	*this = src; // This make assignation called for copy
	std::cout << T_CB << getName() << T_BHID << " is now copied, and has the same initialized attributes." T_N << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=( ScavTrap const &rhs )
{
	this->_hitPoints = rhs._hitPoints;
	this->_maxHitPoints = rhs._maxHitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_maxEnergyPoints = rhs._maxEnergyPoints;
	this->_level = rhs._level;
	this->_name = rhs._name;
	this->_meleeAttackDamage = rhs._meleeAttackDamage;
	this->_rangedAttackDamage = rhs._rangedAttackDamage;
	this->_armorDamageReduction = rhs._armorDamageReduction;
    std::cout << T_BB "ScavTrap Assignation operator overload called for " T_YB << getName() << T_N << std::endl;
	return (*this);	// To return a reference (&Scavtrap), I juste dereference my pointer
}

ScavTrap::~ScavTrap( void )
{
    std::cout << T_BB "ScavTrap Destructor called for... " T_CB << this->_name << T_BB " _> " << T_RI "\"";
	std::cout << clapRandomAnnounce(1) << "\"" << T_N << std::endl;
	return ;
}

void		ScavTrap::beRepaired( unsigned int amount )
{
	// Default settler
	if (amount <= 0 || amount >= this->_maxHitPoints)
	{
		std::cout << T_GY "This is no time to be lazy! Be generous and let's settle restoring hp to 10." << std::endl;
		amount = 10;
	}

	std::cout << T_GY << getName() << " has an advantage on Frag-Trap, in addition to the hp, he can reload energy for free!" << std::endl;
	std::cout << "He can challenge you until infinity... It's his technique to dissuade you from going through the door." T_N << std::endl;
	
	// Energy manager
	if (this->_energyPoints < this->_maxEnergyPoints)
		this->_energyPoints = this->_maxEnergyPoints;

	// HP manager
	if (amount + this->_hitPoints > this->_maxHitPoints)
	{
		std::cout << T_GY "But... a little too greedy with " T_YB << amount;
		std::cout << T_N T_GY " hp request, you know the rule, " T_YB << "100" << T_N T_GY << " is the hp max you can get." T_N << std::endl;
		this->_hitPoints = this->_maxHitPoints;
		clapPresentation();
		std::cout << T_CB T_I << "\"Sweet life juice! I come back for challenging again!\"" T_N  << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	clapPresentation();
	std::cout << T_CB T_I << "\"Healsies! " T_YB << amount << T_CB " hp, I think. Coooming for challenge!\"" T_N  << std::endl;
}

int		ScavTrap::challengeNewcomer(std::string const & target)
{
	std::cout << T_GY "Launching an hilarious challenge costs 25 energy points for " << getName() << ". Having stature is expensive dude." T_N << std::endl;

	std::string challenges[7] = { "Tell a joke saying nothing!", "Explain why robots have a soul...", 
		"Let me win!", "Rub your stomach while banging your head.",
		"Explain why the grass is green.", "Spell the etc word.", "Never come back!!!"};

	std::string style[3] = { "I challenge you to... ", "I defy anyone to... ", "Do you dare to... " };

	if (this->_energyPoints >= 25)
		this->_energyPoints -= 25;
	else
	{
		clapPresentation();
		std::cout << T_CB "\"Hnngh! Empty! Don't have enough energy to launch a challenge... But I can reload energy!\"" T_N << std::endl;
		return (0);
	}
	clapPresentation();
	std::cout << T_CB T_I << "\"Hey " T_YB << target << T_CB ", " << style[rand() % 3];
	std::cout << T_YB << challenges[rand() % 7] << "\"" T_N << std::endl;
	return(1);
}