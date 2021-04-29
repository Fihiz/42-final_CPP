/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:33:16 by salome            #+#    #+#             */
/*   Updated: 2021/04/17 21:49:08 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <time.h>

# define T_N "\033[00m"
# define T_Y "\033[00;33m"
# define T_GN "\033[00;32m"
# define T_GYB "\033[01;90m"
# define T_BB "\033[01;34m"

/* Reinterpret_cast is a type of casting to convert one pointer of another pointer 
** of any type, no matter either the class is related to each other or not.
** It does not check if the pointer type and data pointed by the pointer is same or not. */

/* When we talk about serialization, we mean transforming
** the local data before sending, into a format that the
** receiver can interpret in order to retrieve the initial data. */

struct	Data
{
	std::string		s1;		// A random string
	int				n;	// A second random string
	std::string		s2;		// A random integer
};

void	*serialize( void );
/* Returns the address on the heap of a sequence of bytes
** that represent a piece of serialized data */
Data	*deserialize( void *raw ); 
/* Deserializes the raw data created using "serialize" to a Data structure that 
** contains the same elements that you just serialized and allocated on the heap */


#endif