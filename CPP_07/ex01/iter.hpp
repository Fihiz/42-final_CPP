/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:00:06 by salome            #+#    #+#             */
/*   Updated: 2021/04/19 19:41:19 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

# define T_N "\033[00m"
# define T_Y "\033[00;33m"
# define T_GN "\033[00;32m"
# define T_GYB "\033[01;90m"
# define T_GYI "\033[03;90m"
# define T_BB "\033[01;34m"
# define T_BHID "\033[2;34m"
# define T_GYHID "\033[2;90m"

template< typename T >
void	Tdisplayer( T const &data )
{
	std::cout << T_N T_GYHID "from displayer template: " T_N T_BB;
	std::cout << data << T_N << std::endl;
}

template< typename T >
void	iter( T *array, size_t len, void (*f)(T const &data) )
{
	for(size_t i = 0; i < len; i++)
	{
		std::cout << T_GYHID "From iter template, " T_BB;
		f(array[i]);
	}
}

#endif