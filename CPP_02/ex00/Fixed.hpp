/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:09:32 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/27 12:00:39 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

# define CLEAN "\e[1;1H\e[2J"
# define T_N "\033[00m"
# define T_YB "\033[2;33m"
# define T_GNB "\033[01;32m"
# define T_GN "\033[32m"
# define T_GYB "\033[01;90m"
# define T_GY "\033[00;90m"
# define T_BB "\033[01;34m"
# define T_B "\033[00;34m"
# define T_BHID "\033[2;34m"
# define T_GYHID "\033[2;34m"
# define T_CB "\033[01;36m"
# define T_RB "\033[01;31m"
# define T_R "\033[00;31m"

#include <iostream>

class Fixed
{
	private:
		int					_fixedPointVal;		// Stores my fixed point value
		static const int	_widthBits = 8;		// Stores defined fixed number of bits for fractional part
												// A static member variable is a var that still existing in only one exemplar, no matter the number on instances of it

	public:
		// Coplien form
		Fixed( void );							// Default constructor
		
		Fixed( Fixed const &src);				// Copy constructor, by a new instance of my current class
												// A copy constructor is a member function that initializes an object using another object of the same class 
		
		~Fixed( void );							// Destructor

		Fixed &operator=( Fixed const &rhs ); 	// Assignation operator overload
												// Does not generate a new instance but updates the current one, by Right Hand Side

		int		getRawBits( void ) const; 		// Returns the raw value of a fixed point number
		void	setRawBits( int const raw ); 	// Sets the raw fixed point number value
};

#endif