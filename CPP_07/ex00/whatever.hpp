/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:52:09 by salome            #+#    #+#             */
/*   Updated: 2021/04/18 17:32:20 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

# define T_N "\033[00m"
# define T_Y "\033[00;33m"
# define T_GN "\033[00;32m"
# define T_GYB "\033[01;90m"
# define T_GYI "\033[03;90m"
# define T_BB "\033[01;34m"

class ComplexType {

	public:

		ComplexType( int n ) : _n( n ) { }

		bool operator>=( ComplexType const & rhs ) { return (this->_n >= rhs._n); }
		bool operator<=( ComplexType const & rhs ) { return (this->_n <= rhs._n); }

	private:

		int _n;
};

template< typename T >
void	swap( T &x, T &y ) // Swaps the values of two arguments(so cannot be const), does not return anything
{
	T swap = x;
	x = y;
	y = swap;
}

template< typename T>
T	const	&min( T &x, T &y )	// Compares the two arguments and returns the smallest one
{
	return (y <= x ? y : x);	// If the two arguments are equal, then it returns the second one
}

template< typename T>
T	const	&max( T &x, T &y )	// Compares the two arguments and returns the biggest one
{
	return (y >= x ? y : x);	// If the two arguments are equal, then it returns the second one
}

#endif