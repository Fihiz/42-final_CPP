/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:15:50 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 11:08:35 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/Human.hpp"

int		main()
{
	Human bob;

	std::cout << "With bob identify method_ > \t\t\t\t\t\t\t" << T_BB << bob.identify() << T_N << std::endl;
	std::cout << "With brain identify method, sending pointer by getBrain method_ > \t\t" << T_BB << bob.getBrain().identify() << std::endl;
}

// Testing : clang++ -Wall -Wextra -Werror main.cpp src/Brain.cpp src/Human.cpp
// Checking : valgrind --leak-check=full ./a.out