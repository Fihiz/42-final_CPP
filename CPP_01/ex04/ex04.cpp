/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:57:44 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 10:56:02 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define CLEAN "\e[1;1H\e[2J"
# define T_N "\033[00m"
# define T_YB "\033[2;33m"
# define T_GNB "\033[01;32m"
# define T_GYB "\033[01;90m"
# define T_GY "\033[00;90m"
# define T_BB "\033[01;34m"
# define T_BHID "\033[2;34m"
# define T_GYHID "\033[2;34m"
# define T_CB "\033[01;36m"
# define T_RB "\033[01;31m"
# define T_R "\033[00;31m"

int		main()
{
	std::string brain = "HI THIS IS BRAIN"; // Our original brain string
	std::cout << "Our original string is_ > " << T_BB << brain << std::endl;

	/* Pointer : Remember that a pointer is a variable that holds memory address of another variable,
		need to be dereferenced with [*] operator to access the memory location it points to */
	
	std::string *brainPtr = &brain; // A pointer on my previous brain string, that I initialize on brain string address
	std::cout << T_N "I created a pointer on brain string, called brainPtr, that i initialized on brain address_ > ";
	std::cout << T_BB << *brainPtr << std::endl;

	/* Reference (& is the type to indicate reference) : remember that a reference is kind of non null pointer,
		constant and always dereferenced */
	
	std::string &brainRef = brain; // A reference on my previous brain string, here I directly affect to brainRef the variable
	std::cout << T_N  "I created a reference on brain string, called brainRef, that I initialized by directly assigning the value to it_ > ";
	std::cout << T_BB << brainRef << std::endl;
}

// Testing : clang++ -Wall -Wextra -Werror ex04.cpp
// Checking : valgrind --leak-check=full ./a.out