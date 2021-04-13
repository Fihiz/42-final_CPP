/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:06:06 by salome            #+#    #+#             */
/*   Updated: 2021/04/02 10:37:19 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

/* ****************************** COPLIEN FORM ****************************** */

ScavTrap::ScavTrap( void ) :
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(50),
	_maxEnergyPoints(50),
	_level(1),
	_name("D3F4ULT"),
	_meleeAttackDamage(20),
	_rangedAttackDamage(15),
	_armorDamageReduction(3)
{
    std::cout << T_BB "ScavTrap Default Constructor called" T_N << std::endl;
	return ;
}

/* Polymorphic constructor, to get an entry with a name given as a parameter */

ScavTrap::ScavTrap( std::string const &name ) :
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(50),
	_maxEnergyPoints(50),
	_level(1),
	_name(name),
	_meleeAttackDamage(20),
	_rangedAttackDamage(15),
	_armorDamageReduction(3)
{
    std::cout << T_BB "ScavTrap Name constructor called for " T_CB;
	std::cout << getName() <<  T_BB ", he wants to say hi... _> " << std::endl;
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
	return (*this);	// To return a reference (&ScavTrap), I juste dereference my pointer
}

ScavTrap::~ScavTrap( void )
{
    std::cout << T_BB "ScavTrap Destructor called for... " T_CB << this->_name << T_BB " _> " << T_RI "\"";
	std::cout << scavRandomAnnounce(1) << "\"" << T_N << std::endl;
	return ;
}

/* ************************** GETTERS ************************** */

std::string		ScavTrap::getName( void )
{
	return (this->_name);
}

unsigned int	ScavTrap::getEnergyPoints( void )
{
	return (this->_energyPoints);
}

unsigned int	ScavTrap::getHitPoints( void )
{
	return (this->_hitPoints);
}

unsigned int	ScavTrap::getRangedAttackDamage( void )
{
	return (this->_rangedAttackDamage);
}

unsigned int	ScavTrap::getMeleeAttackDamage( void )
{
	return (this->_meleeAttackDamage);
}

/* ************************ ANNOUNCE ************************ */

std::string		ScavTrap::scavRandomAnnounce( int type )
{
	std::string greetings[3] = { "Greetings Traveller!", "Hey! Over here! I'm over heere!",
		"Yoo hoooooooooo!" };

	std::string farewells[3] = { "I can see... the code", "My servos... are seizing...", 
		"I can see through time..." };

	if (type == 0)
		return(greetings[rand() % 3]);
	else if (type == 1)
		return(farewells[rand() % 3]);
	return (T_GYB "Wut?" T_N );
}

void	ScavTrap::scavPresentation( void )
{
	std::cout << T_WH "SC4V-TP "<< T_GYB << "< " T_CB << getName() << T_GYB << ", energyP(" T_GNB;
	std::cout << getEnergyPoints()  << T_GYB "), hitP(" T_GNB << getHitPoints() << T_GYB ") _> " T_N;
}
/* ************************* FIGHT ************************** */

int		ScavTrap::rangedAttack( std::string const & target )
{
	std::cout << T_GY "Ranged attack costs 7 energy points for " << getName() << "." T_N << std::endl;

	if (this->_energyPoints >= getRangedAttackDamage() / 2)
		this->_energyPoints -= getRangedAttackDamage() / 2;
	else
	{
		scavPresentation();
		std::cout << T_CB "\"CRAAAAAP! Don't have enough energy for ranged attack.\"" T_N;
		return (0);
	}
	scavPresentation();
	std::cout << T_GYB " attacks " T_CB << target << T_YB " at ranged" << T_GYB ", causing ";
	std::cout << T_YB  << this->_rangedAttackDamage << " points of damage!" T_N << std::endl;
	return (1);
}

int			ScavTrap::meleeAttack( std::string const & target )
{
	std::cout << T_GY "Melee attack costs 10 energy points for " << getName() << "." T_N << std::endl;

	if (this->_energyPoints >= getMeleeAttackDamage() / 2)
		this->_energyPoints -= getMeleeAttackDamage() / 2;
	else
	{
		scavPresentation();
		std::cout << T_CB "\"Holy shit! Don't have enough energy for melee attack.\"" T_N << std::endl;
		return (0);
	}
	
	scavPresentation();
	std::cout << T_GYB " attacks " T_CB << target << T_YB " at melee" << T_GYB ", causing ";
	std::cout << T_YB  << this->_meleeAttackDamage << " points of damage!" T_N << std::endl;
	return (1);
}

int		ScavTrap::takeDamage( unsigned int amount )
{
	std::string being_crippled[4] = { "I have many regrets!", "Aww!",
				"You're one screw short of a screw!", "What is that smell? Oh, never mind... it's just you!" };

	// Armor reduction, amount is necessarily 30, 20 or 70 from FragTrap
	amount -= this->_armorDamageReduction;

	// Certain to not go under 0
	if (amount > this->_hitPoints)
		amount = this->_hitPoints;
	this->_hitPoints -= amount;
	scavPresentation();
	if (this->getHitPoints() > 0)
	{
		std::cout << T_CB T_I "\"Why do I even feel pain?! Loosing ";
		std::cout << T_YB << amount << T_CB T_I " hp... " << being_crippled[rand() % 4] << "\"" T_N << std::endl;
		return (0);
	}
	else
	{
		std::cout << T_RB T_I "\"Robot down! I'll get you next time!\"" T_N << std::endl;
		return (1);
	}
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
		scavPresentation();
		std::cout << T_CB T_I << "\"Sweet life juice! I come back for challenging again!\"" T_N  << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	scavPresentation();
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
		scavPresentation();
		std::cout << T_CB "\"Hnngh! Empty! Don't have enough energy to launch a challenge... But I can reload energy!\"" T_N << std::endl;
		return (0);
	}
	scavPresentation();
	std::cout << T_CB T_I << "\"Hey " T_YB << target << T_CB ", " << style[rand() % 3];
	std::cout << T_YB << challenges[rand() % 7] << "\"" T_N << std::endl;
	return(1);
}