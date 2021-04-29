/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:32:52 by salome            #+#    #+#             */
/*   Updated: 2021/04/17 21:52:15 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/A.hpp"
#include "include/B.hpp"
#include "include/C.hpp"

Base    *generate( void )
{
	int	i = rand() % 30;
	
	//std::cout << i << std::endl;
	if (i > 20)
	{
		std::cout << T_BB "\tC has been instantiated" T_N << std::endl;
		return (new C);
	}
	if (i > 10)
	{
		std::cout << T_BB "\tB has been instantiated" T_N << std::endl;
		return (new B);
	}
	else
	{
		std::cout << T_BB "\tA has been instantiated" T_N << std::endl;
		return (new A);
	}
}

void	identify_from_pointer( Base * p ) // Displays "A", "B" or "C" according to the real type of p
{
	std::cout << T_GYB "From pointer: " T_N;
	if (dynamic_cast<A*>(p)) // Checking real type, if pointer is non-null
		std::cout << T_GN "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << T_GN "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << T_GN "C" << std::endl;
	return ;
}

void	identify_from_reference( Base & p) // Displays "A", "B" or "C" according to the real type of p
{
	std::cout << T_GYB "From reference, ";
	identify_from_pointer(&p);
	return ;
}

int		main( void )
{
	srand(time(NULL));

	Base *data1 = generate();
	identify_from_pointer( data1 );
	identify_from_reference( *data1 );
	delete data1;
	std::cout << std::endl;

	Base *data2 = generate();
	identify_from_pointer( data2 );
	identify_from_reference( *data2 );
	delete data2;
	std::cout << std::endl;

	Base *data3 = generate();
	identify_from_pointer( data3 );
	identify_from_reference( *data3 );
	delete data3;
	std::cout << std::endl;

	return (0);
}