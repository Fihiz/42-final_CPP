/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:05:46 by salome            #+#    #+#             */
/*   Updated: 2021/04/19 19:53:58 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

# define T_N "\033[00m"
# define T_Y "\033[00;33m"
# define T_GN "\033[00;32m"
# define T_GYB "\033[01;90m"
# define T_GYI "\033[03;90m"
# define T_BB "\033[01;34m"
# define T_BHID "\033[2;34m"
# define T_GYHID "\033[2;90m"

template< typename T >
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		// Coplien form
		
		// Default constructor
		Array<T>( void )
		{
			// Construction with no parameter: creates an empty array
			std::cout << T_GYHID "Default constructor called" T_N << std::endl;
			this->_array = new T[0]();
			this->_size = 0;
		}
		
		// Unsigned int constructor
		Array<T>( unsigned int n )
		{
			 // Creates an array of n elements, initialized by default
			std::cout << T_GYHID "Unsigned int constructor called" T_N << std::endl;
			this->_array = new T[n](); // Initialization by default
			this->_size = n;
		}
		
		// Copy constructor
		Array<T>( Array<T> const &src )
		{
			std::cout << T_GYHID "Copy constructor called" T_N << std::endl;
			*this = src; // Calling assignation operator overload
		}
		
		// Assignation operator overload
		Array<T> &operator=( Array<T> const &rhs )
		{
			std::cout << T_GYHID "Assignation operator overload called" T_N << std::endl;
			this->_size = rhs.size();
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = rhs._array[i];
			return (*this);
		}
		
		// Destructor
		~Array<T>( void )
		{
			std::cout << T_GYHID "Destructor called" T_N << std::endl;
			if (this->_array)
				delete[] this->_array;
		}

		// Getter
		unsigned int	size( void ) const
		{
			return (this->_size);
		}

		// Method
		T		&operator[]( unsigned int i )
		{
			if (i >= size())
				throw (std::out_of_range(T_Y "The index you passed is currently out of bounds." T_N ));
			else
				return (this->_array[i]);
		}

};

#endif