/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:17:42 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/27 12:06:00 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int		main(void) 
{
	Fixed a;		// Calls default constructor
	Fixed b(a);		// Calls copy constructor, to copy a in b (so it calls methods)
	Fixed c;		// Calls default constructor

	c = b;			// Calls assignation operator overload, to update c with b (so it calls destructor and methods)
	
	std::cout << a.getRawBits() << std::endl; // All might have the same display, by three different ways
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;		// Destroys my three instances
}

// Testing: clang++ -Wall -Wextra -Werror Fixed.cpp main.cpp