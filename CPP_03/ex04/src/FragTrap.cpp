/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:11:13 by salome            #+#    #+#             */
/*   Updated: 2021/04/02 11:14:48 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

/* ****************************** COPLIEN FORM ****************************** */

FragTrap::FragTrap( void )
{
    std::cout << T_BB "FragTrap Default Constructor called" T_N << std::endl;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_meleeAttackDamage = 30;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;

	//std::cout << "hp: " << this->_hitPoints << std::endl;
	//std::cout << "hp max: " << this->_maxHitPoints << std::endl;
	//std::cout << "energy: " << this->_energyPoints << std::endl;
	//std::cout << "energy max: " << this->_maxEnergyPoints << std::endl;
	//std::cout << "level: " << this->_level << std::endl;
	//std::cout << "meleeDamage: " << this->_meleeAttackDamage << std::endl;
	//std::cout << "rangedDamage: " << this->_rangedAttackDamage << std::endl;
	//std::cout << "armorReduction: " << this->_armorDamageReduction << std::endl;
	return ;
}

/* Polymorphic constructor, to get an entry with an int, 
** to differ from default or name constructor and edit values 
** in case of diamond inheritance */

FragTrap::FragTrap( int preset )
{
	preset = 0;
    std::cout << T_BB "FragTrap Diamond Constructor called" T_N << std::endl;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;

	//std::cout << "hp: " << this->_hitPoints << std::endl;
	//std::cout << "hp max: " << this->_maxHitPoints << std::endl;
	//std::cout << "rangedDamage: " << this->_rangedAttackDamage << std::endl;
	//std::cout << "armorReduction: " << this->_armorDamageReduction << std::endl;
	return ;
}

/* Polymorphic constructor, to get an entry with a name given in param */

FragTrap::FragTrap( std::string const &name )
{
    std::cout << T_BB "FragTrap Name constructor called for " T_CB;
	this->_name = name;
	std::cout << getName() <<  T_BB ", he's settling his attributes and wants to be the best, but... _> " << std::endl;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_meleeAttackDamage = 30;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;
	return ;
}

FragTrap::FragTrap( FragTrap const &src )
{
    std::cout << T_BB "FragTrap Copy Constructor called" T_N << std::endl;
	*this = src; // This make assignation called for copy
	std::cout << T_CB << getName() << T_BHID << " is now copied, and has the same initialized attributes." T_N << std::endl;
	return ;
}

FragTrap &FragTrap::operator=( FragTrap const &rhs )
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
    std::cout << T_BB "FragTrap Assignation operator overload called for " T_YB << getName() << T_N << std::endl;
	return (*this);	// To return a reference (&Fragtrap), I juste dereference my pointer
}

FragTrap::~FragTrap( void )
{
    std::cout << T_BB "FragTrap Destructor called for... " T_CB << this->_name << T_BB " _> " << T_RI "\"";
	std::cout << clapRandomAnnounce(1) << "\"" << T_N << std::endl;
	return ;
}

/* ************************** GETTERS ************************** */

unsigned int	FragTrap::getVaultAttackDamage( void )
{
	return (this->_vaultAttackDamage);
}

/* ************************** FIGHT **************************** */

int		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::cout << T_GY "Elegant attack costs 25 energy points for " << getName() << ". Having style is expensive dude." T_N << std::endl;

	std::string attacks[5] = { "Miniontrap", "Torgue Fiesta", "Gun Wizard", "Shhh... Trap!", "Funzerker" };

	std::string style[5] = { "I am a tornado of death and bullets!", "Take that!", "Cryo me a river!", 
								"It's like a box of chocolates...", "I'm a sexy dinosaur! Rawr!" };

	if (this->_energyPoints >= 25)
		this->_energyPoints -= 25;
	else
	{
		clapPresentation();
		std::cout << T_CB "\"No, nononono NO! Don't have enough energy for my elegant attack.\"" T_N;
		return (0);
	}
	clapPresentation();
	std::cout << T_CB T_I << "\"" << style[rand() % 5] << "\"" T_N;
	std::cout << T_GYB " attacks " T_CB << target << T_GYB " with " T_YB << attacks[rand() % 5];
	std::cout << T_GYB " causing " << T_YB  << 70 << " points of damage!" T_N << std::endl;
	return (1);
}

void		FragTrap::beRepaired( unsigned int amount )
{
	// Default settler
	if (amount <= 0 || amount >= 100)
	{
		std::cout << T_GY "This is no time to be lazy! Be generous and let's settle restoring hp to 10." << std::endl;
		amount = 10;
	}

	std::cout << T_GY "BeRepaired costs "<< amount / 2 <<  " energy points for " << getName() << "." T_N << std::endl;
	
	// Energy manager
	if (this->_energyPoints >= amount / 2)
		this->_energyPoints -= amount / 2;
	else
	{
		std::cout << T_GY "Nothing ventured, nothing gained but... " T_N << std::endl;
		clapPresentation();
		std::cout << T_CB "\"Crap! Don't have enough energy for beRepaired with as many hp... NOOOO!\"" T_N << std::endl;
		return ;
	}

	// HP manager
	if (amount + this->_hitPoints > this->_maxHitPoints)
	{
		std::cout << T_GY "A little too greedy with " T_YB << amount;
		std::cout << T_N T_GY " hp request, you know the rule, " T_YB << "100" << T_N T_GY << " is the hp max you can get." T_N << std::endl;
		this->_hitPoints = this->_maxHitPoints;
		clapPresentation();
		std::cout << T_CB T_I << "\"Health! Eww, what flavor is red? \"" T_N  << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	clapPresentation();
	std::cout << T_CB T_I << "\"Health over here! " T_YB << amount << T_CB " hp in plus, I think. Am I leaking?\"" T_N  << std::endl;
}