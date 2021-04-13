/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:38:09 by salome            #+#    #+#             */
/*   Updated: 2021/04/02 10:53:37 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

/* ****************************** COPLIEN FORM ****************************** */

ClapTrap::ClapTrap( void ) :
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(100),
	_maxEnergyPoints(100),
	_level(1),
	_name("C404"),
	_meleeAttackDamage(0),
	_rangedAttackDamage(0),
	_armorDamageReduction(0)
{
    std::cout << T_GY "ClapTrap Default Constructor called, " << T_PU "a Robot is coming... !" T_N << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const &src )
{
    std::cout << T_BB "ClapTrap Copy Constructor called, a Robot copy is coming... !" T_N << std::endl;
	*this = src; // This make assignation called for copy
	std::cout << T_CB << getName() << T_BHID << " is now copied, and has the same initialized attributes." T_N << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=( ClapTrap const &rhs )
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
    std::cout << T_BB "ClapTrap Assignation operator overload called for " T_YB << getName() << T_N << std::endl;
	return (*this);	// To return a reference (&ClapTrap), I juste dereference my pointer
}

ClapTrap::~ClapTrap( void )
{
    std::cout << T_GY "ClapTrap Destructor called, RIP little " << getName() << T_N << std::endl;
	return ;
}

/* ************************** GETTERS ************************** */

std::string		ClapTrap::getName( void )
{
	return (this->_name);
}

unsigned int	ClapTrap::getEnergyPoints( void )
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getHitPoints( void )
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getRangedAttackDamage( void )
{
	return (this->_rangedAttackDamage);
}

unsigned int	ClapTrap::getMeleeAttackDamage( void )
{
	return (this->_meleeAttackDamage);
}

/* ************************ ANNOUNCE ************************ */

std::string		ClapTrap::clapRandomAnnounce( int type )
{
	std::string greetings[7] = { "Hey everybody! Check out my package!", "Let's get this party started!",
		"This time it'll be awesome, I promise!", "Look out everybody! Things are about to get awesome!",
		"Greetings Traveller!", "Hey! Over here! I'm over heere!", "Yoo hoooooooooo!"};

	std::string farewells[7] = { "The robot is dead, long live the robot!", "Don't forget me!", 
		"I'll stop talking when I'm dead!", "I'll die the way I lived: annoying!", 
		"I can see... the code", "My servos... are seizing...", "I can see through time..."};

	if (type == 0)
		return(greetings[rand() % 7]);
	else if (type == 1)
		return(farewells[rand() % 7]);
	else if (type == 2)
		return ("I am so impressed with myself! Time to die in hero!");
	else if (type == 3)
		return ("Ha ha, this is in no way surprising! Ha ha! Time to go now!");
	else if (type == 4)
		return ("Still both alive? This could've gone better! Defragmenting!");
	return (T_GYB "Wut?" T_N );
}

void	ClapTrap::clapPresentation( void )
{
	std::cout << T_GYB "??4G-TP < " T_CB << getName() << T_GYB << ", energyP(" T_GNB;
	std::cout << getEnergyPoints()  << T_GYB "), hitP(" T_GNB << getHitPoints() << T_GYB ") _> " T_N;
}

/* ************************* FIGHT ************************** */

int		ClapTrap::rangedAttack( std::string const & target )
{
	std::cout << T_GY "Ranged attack costs " << getRangedAttackDamage() / 2 << "energy points for " << getName() << "." T_N << std::endl;

	if (this->_energyPoints >= getRangedAttackDamage() / 2)
		this->_energyPoints -= getRangedAttackDamage() / 2;
	else
	{
		clapPresentation();
		std::cout << T_CB "\"Crap! NOOOOO! Don't have enough energy for ranged attack.\"" T_N;
		return (0);
	}
	clapPresentation();
	std::cout << T_GYB " attacks " T_CB << target << T_YB " at ranged" << T_GYB ", causing ";
	std::cout << T_YB  << this->_rangedAttackDamage << " points of damage!" T_N << std::endl;
	return (1);
}

int			ClapTrap::meleeAttack( std::string const & target )
{
	std::cout << T_GY "Melee attack costs " << getMeleeAttackDamage() / 2 << "energy points for " << getName() << "." T_N << std::endl;

	if (this->_energyPoints >= getMeleeAttackDamage() / 2)
		this->_energyPoints -= getMeleeAttackDamage() / 2;
	else
	{
		clapPresentation();
		std::cout << T_CB "\"Crap! Don't have enough energy for melee attack.\"" T_N << std::endl;
		return (0);
	}
	
	clapPresentation();
	std::cout << T_GYB " attacks " T_CB << target << T_YB " at melee" << T_GYB ", causing ";
	std::cout << T_YB  << this->_meleeAttackDamage << " points of damage!" T_N << std::endl;
	return (1);
}

int		ClapTrap::takeDamage( unsigned int amount )
{
	std::string being_crippled[8] = { "You can't kill me!", "Aww! Come on!",
		"I bet your mom could do better!", "I'm too pretty to die!", "I have many regrets!",
		"Aww!", "You're one screw short of a screw!", "What is that smell? Oh, never mind... it's just you!"};

	// Armor reduction
	amount -= this->_armorDamageReduction;

	// Certain to not go under 0
	if (amount > this->_hitPoints)
		amount = this->_hitPoints;
	this->_hitPoints -= amount;
	clapPresentation();
	if (this->getHitPoints() > 0)
	{
		std::cout << T_CB T_I "\"My robotic flesh! AAHH! Armor soak increased! Loosing ";
		std::cout << T_YB << amount << T_CB T_I " hp... " << being_crippled[rand() % 8] << "\"" T_N << std::endl;
		return (0);
	}
	else
	{
		std::cout << T_RB T_I "\"Robot down! I'll get you next time!\"" T_N << std::endl;
		return (1);
	}
}
