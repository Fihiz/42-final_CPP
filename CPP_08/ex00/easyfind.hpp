/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:38:23 by salome            #+#    #+#             */
/*   Updated: 2021/04/21 20:40:20 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <stdexcept>

# define T_N "\033[00m"
# define T_Y "\033[00;33m"
# define T_GN "\033[00;32m"
# define T_GYB "\033[01;90m"
# define T_GYI "\033[03;90m"
# define T_GYHID "\033[2;90m"
# define T_BB "\033[01;34m"

/* std::list<int>::const_iterator it; 
** Here I instantiate a const_iterator through an int list, can be read as:
** "in an int list namespace, I want a const_iterator" (cf nested classes)) */

template< typename T >
typename T::const_iterator		easyfind( T const &tContainer, int nToFind )
{
	typename T::const_iterator	it;
	typename T::const_iterator	ite = tContainer.end(); // .end() is not the last value but, its overflow (+1)

	std::cout << T_GYI "Looking for " << nToFind << ": ";
	for (it = tContainer.begin(); it != ite; it++)
	{
		if (*it == nToFind)
		{
			std::cout << T_BB "Match found" T_N << std::endl;
			return (it);
		}
	}
	throw (std::out_of_range(T_Y "No match found" T_N));
}

#endif