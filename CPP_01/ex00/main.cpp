/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:55:09 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/22 09:45:07 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "Pony.hpp"

void	ponyOnTheStack( void )
{
	Pony	stackPony = Pony("Carrot", "Shetland", "Chestnut");
	stackPony.getPonyStackInfos();
	stackPony.getPonyStackActions(3, 20);
	std::cout << T_GNB "Now implicitly calling stackPony destructor by the return of our main" T_N << std::endl;
}

void	ponyOnTheHeap( void )
{
	Pony*	heapPony = new Pony("LittleMagicStar", "Connemara", "Caramel");
	heapPony->getPonyHeapInfos();
	heapPony->getPonyHeapActions(5, 45);
	std::cout << T_GNB "Calling delete for heapPony, Pony destructor will be called implicitly" T_N << std::endl;
	delete heapPony; //heapPony is destroyed
}

int		main()
{
	ponyOnTheHeap();
	ponyOnTheStack();

	return (0); //stackPony is destroyed implicitly
}

// Testing : clang++ -Wall -Wextra -Werror main.cpp Pony.cpp -o pony
// Checking : valgrind --leak-check=full ./a.out