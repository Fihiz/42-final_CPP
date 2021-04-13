/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:29:44 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 11:32:53 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/HumanA.hpp"
#include "include/HumanB.hpp"

int		main()
{
	/* Rule -> If at a moment, it has to disappear or not exist, or change : I use a pointer.
		If it has to always being existing, I'll use a reference. */
	{
		Weapon club = Weapon("crude spiked club"); //A reference always refer to something and can't be null
		HumanA bob("Bob", club); //All is given, so I can use reference from constructor until destructor
		bob.attack();
		club.setType("some other type of club"); //Reference allows to change of pointer but always have reference to its value
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim"); //Here I can't use reference, weapon is not given, I may use pointer
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club"); //Won't get the current val if I don't use a Weapon pointer
		jim.attack();
	}
}

// Testing : clang++ -Wall -Wextra -Werror main.cpp src/Weapon.cpp src/HumanA.cpp src/HumanB.cpp
// Checking : valgrind --leak-check=full ./a.out