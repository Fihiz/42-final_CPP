/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:09:33 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/04 23:17:10 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointVal(0)
{
	std::cout << T_BB "Default Constructor called" T_N << std::endl;
	return ;
}


/*Polymorphism, overloaded function with a constructor that takes a constant integer as a parameter 
** and that converts it to the correspondant fixed(8) point value */
Fixed::Fixed( int const n )
{
	std::cout << T_BB "Int constructor called with " T_GYB << n << T_BB " value " << T_N << std::endl;
	this->_fixedPointVal = (n << this->_widthBits); //Settling its correspondant fixed value by [8] left bit shift
	return;
}


/*Polymorphism, overloaded function with a constructor that takes a constant floating point as a parameter 
** and that converts it to the correspondant fixed(8) point value */
Fixed::Fixed( float const f )
{
	std::cout << T_BB "Float constructor called with " T_GYB << f << T_BB " value " << T_N << std::endl;
	// Recall all arithmetics on fixed point numbers are the same as integer, we can simply reuse the integer type int in C to perform fixed point arithmetic. 
	this->_fixedPointVal = roundf(f * (1 << this->_widthBits)); //Arrounding our float to then be able to settle its fixed value by [8] left bit
	return;
}

Fixed::Fixed( Fixed const &src ) // New instance
{
	std::cout << T_BB "Copy Constructor called" T_N << std::endl;
	*this = src;
	return ;
}

Fixed &Fixed::operator=( Fixed const &rhs )
{
	std::cout << T_BB "Assignation operator called" T_N << std::endl;
	this->_fixedPointVal = rhs.getRawBits();
	return (*this); // To return a ref on it (&Fixed), I just dereference my pointer
}

Fixed::~Fixed( void )
{
	std::cout << T_BB "Destructor called" T_N << std::endl;
	return ;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << T_BB "getRawbits member function called" T_N << std::endl;
	return(this->_fixedPointVal); // Returns a fixedPointVal copy
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << T_BB "setRawBits member function called" T_N << std::endl;
	this->_fixedPointVal = raw; // Assigns the raw value to fixedPointVal
}

float	Fixed::toFloat( void ) const // Converts the fixed point value to a floating point value (looks like "it does anything" in case of int (0 = 0.0...))
{
	return((float)(this->_fixedPointVal / (float)(1 << this->_widthBits))); // Bit shifting in the opposite way to returns its original value, so [*] becomes [/]
}

int		Fixed::toInt( void ) const // Converts the fixed point value to an integer value
{
	return((int)(this->_fixedPointVal >> this->_widthBits)); // Bit shifting in the opposite way to returns its original value
}

std::ostream &operator<<( std::ostream &o, const Fixed &rhs ) // An overload to the [«] operator that inserts a floating point representation of the fixed point value into the parameter output stream
{
	o << rhs.toFloat();
    return (o);
}

/* The goal is to realize that a bit pattern is common to all our values...
** std::cout << T_GN "Int fixed point val gives " T_GYB << this->_fixedPointVal << ", 
** (10 * 256), 256 is 2 power of 8" << T_N << std::endl */

/* First step is to receive an int or a float in the dedicated constructor,
** that settles its correspondant fixed point value by 8 (as intended) left bit shift. */

/* Second step is to print our previous fixed point values we settled, 
** by their original value (int or float), reproducing the 8 bit shift in the opposite (right) way.
** So it displays the same value as we received in constructor param. */

/* Final step is to display their integer value representation */