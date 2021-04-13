/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:26:57 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/02 10:27:51 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ****************************** COPLIEN FORM ****************************** */

FragTrap::FragTrap( void ) :
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(100),
	_maxEnergyPoints(100),
	_level(1),
	_name("DF4ULT"),
	_meleeAttackDamage(30),
	_rangedAttackDamage(20),
	_armorDamageReduction(5)
{
    std::cout << T_BB "FragTrap Default Constructor called" T_N << std::endl;
	return ;
}

/* Polymorphic constructor, to get an entry with a name given as a parameter */

FragTrap::FragTrap( std::string const &name ) :
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(100),
	_maxEnergyPoints(100),
	_level(1),
	_name(name),
	_meleeAttackDamage(30),
	_rangedAttackDamage(20),
	_armorDamageReduction(5)
{
    std::cout << T_BB "FragTrap Name Constructor called for " T_CB;
	std::cout << getName() <<  T_BB ", he wants to loudly announce himself... _> " << std::endl;
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
	std::cout << fragRandomAnnounce(1) << "\"" << T_N << std::endl;
	return ;
}

/* ************************** GETTERS ************************** */

std::string		FragTrap::getName( void )
{
	return (this->_name);
}

unsigned int	FragTrap::getEnergyPoints( void )
{
	return (this->_energyPoints);
}

unsigned int	FragTrap::getHitPoints( void )
{
	return (this->_hitPoints);
}

unsigned int	FragTrap::getRangedAttackDamage( void )
{
	return (this->_rangedAttackDamage);
}

unsigned int	FragTrap::getMeleeAttackDamage( void )
{
	return (this->_meleeAttackDamage);
}

unsigned int	FragTrap::getVaultAttackDamage( void )
{
	return (this->_vaultAttackDamage);
}

/* ************************ ANNOUNCE ************************ */

std::string		FragTrap::fragRandomAnnounce( int type )
{
	std::string greetings[4] = { "Hey everybody! Check out my package!", "Let's get this party started!",
		"This time it'll be awesome, I promise!", "Look out everybody! Things are about to get awesome!" };

	std::string farewells[4] = { "The robot is dead, long live the robot!", "Don't forget me!", 
		"I'll stop talking when I'm dead!", "I'll die the way I lived: annoying!"};

	if (type == 0)
		return(greetings[rand() % 4]);
	else if (type == 1)
		return(farewells[rand() % 4]);
	else if (type == 2)
		return ("I am so impressed with myself! Time to die in hero!");
	else if (type == 3)
		return ("Ha ha, this is in no way surprising! Ha ha! Time to go now!");
	else if (type == 4)
		return ("Still both alive? This could've gone better! Defragmenting!");
	return (T_GYB "Wut?" T_N );
}

void	FragTrap::fragPresentation( void )
{
	std::cout << T_GYB "FR4G-TP < " T_CB << getName() << T_GYB << ", energyP(" T_GNB;
	std::cout << getEnergyPoints()  << T_GYB "), hitP(" T_GNB << getHitPoints() << T_GYB ") _> " T_N;
}

/* ************************* FIGHT ************************** */

int		FragTrap::rangedAttack( std::string const & target )
{
	std::cout << T_GY "Ranged attack costs 10 energy points for " << getName() << "." T_N << std::endl;

	if (this->_energyPoints >= 10)
		this->_energyPoints -= 10;
	else
	{
		fragPresentation();
		std::cout << T_CB "\"Crap! Don't have enough energy for ranged attack.\"" T_N;
		return (0);
	}
	fragPresentation();
	std::cout << T_GYB " attacks " T_CB << target << T_YB " at ranged" << T_GYB ", causing ";
	std::cout << T_YB  << this->_rangedAttackDamage << " points of damage!" T_N << std::endl;
	return (1);
}

int			FragTrap::meleeAttack( std::string const & target )
{
	std::cout << T_GY "Melee attack costs 15 energy points for " << getName() << "." T_N << std::endl;

	if (this->_energyPoints >= 15)
		this->_energyPoints -= 15;
	else
	{
		fragPresentation();
		std::cout << T_CB "\"Crap! Don't have enough energy for melee attack.\"" T_N << std::endl;
		return (0);
	}
	
	fragPresentation();
	std::cout << T_GYB " attacks " T_CB << target << T_YB " at melee" << T_GYB ", causing ";
	std::cout << T_YB  << this->_meleeAttackDamage << " points of damage!" T_N << std::endl;
	return (1);
}

int		FragTrap::takeDamage( unsigned int amount )
{
	std::string being_crippled[4] = { "You can't kill me!", "Aww! Come on!",
				"I bet your mom could do better!", "I'm too pretty to die!" };

	// Armor reduction, amount is necessarily 30, 20 or 70
	amount -= this->_armorDamageReduction;

	// Certain to not go under 0
	if (amount > this->_hitPoints)
		amount = this->_hitPoints;
	this->_hitPoints -= amount;
	fragPresentation();
	if (this->getHitPoints() > 0)
	{
		std::cout << T_CB T_I "\"My robotic flesh! AAHH! Armor soak increased! Loosing ";
		std::cout << T_YB << amount << T_CB T_I " hp... " << being_crippled[rand() % 4] << "\"" T_N << std::endl;
		return (0);
	}
	else
	{
		std::cout << T_RB T_I "\"Robot down! I'll get you next time!\"" T_N << std::endl;
		return (1);
	}
}

void		FragTrap::beRepaired( unsigned int amount )
{
	// Default settler (case of wrong value)
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
		fragPresentation();
		std::cout << T_CB "\"Crap! Don't have enough energy for beRepaired with as many hp... NOOOO!\"" T_N << std::endl;
		return ;
	}

	// HP manager
	if (amount + this->_hitPoints > this->_maxHitPoints)
	{
		std::cout << T_GY "A little too greedy with " T_YB << amount;
		std::cout << T_N T_GY " hp request, you know the rule, " T_YB << "100" << T_N T_GY << " is the hp max you can get." T_N << std::endl;
		this->_hitPoints = this->_maxHitPoints;
		fragPresentation();
		std::cout << T_CB T_I << "\"Health! Eww, what flavor is red? \"" T_N  << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	fragPresentation();
	std::cout << T_CB T_I << "\"Health over here! " T_YB << amount << T_CB " hp in plus, I think. Am I leaking?\"" T_N  << std::endl;
}

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
		fragPresentation();
		std::cout << T_CB "\"No, nononono NO! Don't have enough energy for my elegant attack.\"" T_N;
		return (0);
	}
	fragPresentation();
	std::cout << T_CB T_I << "\"" << style[rand() % 5] << "\"" T_N;
	std::cout << T_GYB " attacks " T_CB << target << T_GYB " with " T_YB << attacks[rand() % 5];
	std::cout << T_GYB " causing " << T_YB  << 70 << " points of damage!" T_N << std::endl;
	return(1);
}