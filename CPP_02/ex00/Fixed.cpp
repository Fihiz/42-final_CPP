/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:09:33 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/27 12:01:15 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default Constructor
Fixed::Fixed( void ) : _fixedPointVal(0)
{
	std::cout << T_BB "Default Constructor called" T_N << std::endl;
	return ;
}

// Copy Constructor (performs the copy, member to member, from src(current object) to dest/this(copy object))
Fixed::Fixed( Fixed const &src ) // New instance
{
	std::cout << T_BB "Copy Constructor called" T_N << std::endl;
	*this = src;
	return ;
}

// Assignation operator overload (does not make a copy but an affectation to the already created object, so It calls the destructor and assigns)
Fixed &Fixed::operator=( Fixed const &rhs )
{
	std::cout << T_BB "Assignation operator called" T_N << std::endl;
	this->_fixedPointVal = rhs.getRawBits();
	return (*this); // To return a ref on it (&Fixed), I just dereference my pointer
}

// Destructor
Fixed::~Fixed( void )
{
	std::cout << T_BB "Destructor called" T_N << std::endl;
	return ;
}

// Getter
int		Fixed::getRawBits( void ) const
{
	std::cout << T_BB "getRawbits member function called" T_N << std::endl;
	return(this->_fixedPointVal); // Returns a fixedPointVal copy
}

// Setter
void	Fixed::setRawBits(int const raw)
{
	std::cout << T_BB "setRawBits member function called" T_N << std::endl;
	this->_fixedPointVal = raw; // Assigns the raw value to fixedPointVal
}
