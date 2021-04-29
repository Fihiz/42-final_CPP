/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:02:07 by salome            #+#    #+#             */
/*   Updated: 2021/04/21 20:56:39 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

# define T_N "\033[00m"
# define T_Y "\033[00;33m"
# define T_GN "\033[00;32m"
# define T_GYB "\033[01;90m"
# define T_GYI "\033[03;90m"
# define T_BB "\033[01;34m"

class Span
{
	private:
		unsigned int		_storage;
		unsigned int		_sum;
		std::vector<int>	*_tab;
		Span( void );								// Default constructor
	
	public:
		// Coplien form
		Span( unsigned int N );						// Unsigned int constructor
		Span( Span const &src );					// Copy constructor
		Span &operator=( Span const &rhs );			// Assignation operator overload
		virtual ~Span( void );						// Destructor

		// Nested classes for exception handling (must not be coplien)
		class	SpanAlreadyFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();		// Returns a string that describe what error occured
		};
		class	SpanNotFilledEnoughException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// Getters
		unsigned int	getStorage( void );
		unsigned int	getSum( void );

		// Methods
		void			addNumber( int val );
		void			addNumber( int begin, int end );
		int				shortestSpan( void );
		int				longestSpan( void );
		// Additional methods
		void			displayTab( void );
};

#endif
