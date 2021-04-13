/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:01:16 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 20:16:43 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

void	memoryLeak()
{
	std::string* panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;
	delete panthere; //As malloc and free, [new] call requires [delete] call
}

 int	main()
 {
 	memoryLeak();
 	return (0);
 }

// Testing : clang++ -Wall -Wextra -Werror ex01.cpp
// Checking : valgrind --leak-check=full ./a.out