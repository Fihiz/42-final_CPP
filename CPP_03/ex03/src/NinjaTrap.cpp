/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:22:03 by salome            #+#    #+#             */
/*   Updated: 2021/04/02 11:00:03 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/NinjaTrap.hpp"

/* ****************************** COPLIEN FORM ****************************** */

NinjaTrap::NinjaTrap( void )
{
    std::cout << T_BB "NinjaTrap Default Constructor called" T_N << std::endl;
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 5;
	this->_armorDamageReduction = 0;
	return ;
}

/* Polymorphic constructor, to get an entry with a name given as a parameter */

NinjaTrap::NinjaTrap( std::string const &name )
{
    std::cout << T_BB "NinjaTrap Name constructor called for " T_CB;
	this->_name = name;
	std::cout << getName() <<  T_BB ", he's settling his attributes and wants to teach you the art of fighting... _> " << std::endl;
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 5;
	this->_armorDamageReduction = 0;
	return ;
}

NinjaTrap::NinjaTrap( NinjaTrap const &src )
{
    std::cout << T_BB "NinjaTrap Copy Constructor called" T_N << std::endl;
	*this = src; // This make assignation called for copy
	std::cout << T_CB << getName() << T_BHID << " is now copied, and has the same initialized attributes." T_N << std::endl;
	return ;
}

NinjaTrap &NinjaTrap::operator=( NinjaTrap const &rhs )
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
    std::cout << T_BB "NinjaTrap Assignation operator overload called for " T_YB << getName() << T_N << std::endl;
	return (*this);	// To return a reference (&NinjaTrap), I juste dereference my pointer
}

NinjaTrap::~NinjaTrap( void )
{
    std::cout << T_BB "NinjaTrap Destructor called for... " T_CB << this->_name << T_BB " _> " << T_RI "\"";
	std::cout << clapRandomAnnounce(1) << "\"" << T_N << std::endl;
	return ;
}

///* ************************* FIGHT ************************** */

void		NinjaTrap::beRepaired( unsigned int amount )
{
	// Default settler
	if (amount <= 0 || amount >= 60)
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
		std::cout << T_N T_GY " hp request, you know the rule, " T_YB << "60" << T_N T_GY << " is the hp max you can get." T_N << std::endl;
		this->_hitPoints = this->_maxHitPoints;
		clapPresentation();
		std::cout << T_CB T_I << "\"Health! Eww, what flavor is red? \"" T_N  << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	clapPresentation();
	std::cout << T_CB T_I << "\"Health over here! " T_YB << amount << T_CB " hp in plus, I think. Am I leaking?\"" T_N  << std::endl;
}

int			NinjaTrap::ninjaShoebox( ClapTrap &target )
{
	std::cout << T_GY "A ninja has more than one trick in his shoe." T_N << std::endl;
	std::cout << T_GY "It costs 25 energy points for " << getName() << ". Best things are the most expensive." T_N << std::endl;
	std::cout << T_GY "ClapTrap... come one, he says!" T_N << std::endl;
	if (this->_energyPoints >= 25)
		this->_energyPoints -= 25;
	else
	{
		clapPresentation();
		std::cout << T_CB "\"Crap... Don't have enough energy for my invisible attack.\"" T_N;
		return (0);
	}
	clapPresentation();
	std::cout << T_GYB " attacks " T_CB << target.getName();
	std::cout << T_GYB ", causing " << T_YB  << getMeleeAttackDamage() << " points of damage!" T_N << std::endl;
	target.takeDamage(getMeleeAttackDamage());
	return (1);
}

int			NinjaTrap::ninjaShoebox( FragTrap &target )
{
	std::cout << T_GY "A ninja has more than one trick in his shoe." T_N << std::endl;
	std::cout << T_GY "It costs 25 energy points for " << getName() << ". Best things are the most expensive." T_N << std::endl;
	std::cout << T_GY "Poor FragTrap, he says!" T_N << std::endl;
	if (this->_energyPoints >= 25)
		this->_energyPoints -= 25;
	else
	{
		clapPresentation();
		std::cout << T_CB "\"Crap... Don't have enough energy for my invisible attack.\"" T_N;
		return (0);
	}
	clapPresentation();
	std::cout << T_GYB " attacks " T_CB << target.getName();
	std::cout << T_GYB ", causing " << T_YB  << getMeleeAttackDamage() << " points of damage!" T_N << std::endl;
	target.takeDamage(getMeleeAttackDamage());
	return (1);
}

int				NinjaTrap::ninjaShoebox( ScavTrap &target )
{
	std::cout << T_GY "A ninja has more than one trick in his shoe." T_N << std::endl;
	std::cout << T_GY "It costs 25 energy points for " << getName() << ". Best things are the most expensive." T_N << std::endl;
	std::cout << T_GY "Come on little ScavTrap, he says!" T_N << std::endl;
	if (this->_energyPoints >= 25)
		this->_energyPoints -= 25;
	else
	{
		clapPresentation();
		std::cout << T_CB "\"Crap... Don't have enough energy for my invisible attack.\"" T_N;
		return (0);
	}
	clapPresentation();
	std::cout << T_GYB " attacks " T_CB << target.getName();
	std::cout << T_GYB ", causing " << T_YB  << getMeleeAttackDamage() << " points of damage!" T_N << std::endl;
	target.takeDamage(getMeleeAttackDamage());
	return (1);
}

int				NinjaTrap::ninjaShoebox( NinjaTrap &target )
{
	std::cout << T_GY "A ninja takes care of himself and his peers." T_N << std::endl;
	std::cout << T_GY "It costs 25 energy points for " << getName() << ". Best things are the most expensive." T_N << std::endl;
	std::cout << T_GY "Come on Ninja, you're the best, he says!" T_N << std::endl;
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