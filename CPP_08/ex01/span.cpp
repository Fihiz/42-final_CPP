/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:02:02 by salome            #+#    #+#             */
/*   Updated: 2021/04/21 21:38:29 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

// Coplien form

Span::Span( unsigned int N ) : _storage(N)
{
	std::cout << T_GYI "Unsigned int constructor called" T_N << std::endl;
	this->_tab = new std::vector<int>[this->_storage];
	this->_sum = 0;
	return ;
}

Span::Span( Span const &src )
{
	std::cout << T_GYI "Copy constructor called" T_N << std::endl;
	*this = src;
	return ;
}

Span	&Span::operator=( Span const &rhs )
{
	std::cout << T_GYI "Assignation operator overload called" T_N << std::endl;
	this->_storage = rhs._storage;
	this->_sum = rhs._sum;
	this->_tab = new std::vector<int>[this->_storage];
	for(unsigned int i = 0; i < getSum(); i++)
		this->_tab[i] = rhs._tab[i];
	return (*this);
}

Span::~Span( void )
{
	std::cout << T_GYI "Destructor called" T_N << std::endl;
	if (this->_tab)
		delete[] this->_tab;
	return ;
}


// Getters
unsigned int	Span::getStorage( void )
{
	return (this->_storage);
}

unsigned int	Span::getSum( void )
{
	return (this->_sum);
}


// Methods

static	void	displayInt( int i )
{
	std::cout << T_GYB "Tab content: ";
	std::cout << T_BB << i << T_N << std::endl;
	return ;
}

void	Span::displayTab( void )
{
	if (getSum() > 0) // Protection
		for_each(this->_tab->begin(), this->_tab->end(), displayInt);
	return ;
}

void			Span::addNumber( int val )
{
	if (getSum() == getStorage())
		throw Span::SpanAlreadyFullException();

	this->_tab->push_back(val);
	this->_sum += 1;
	return ;
}

void			Span::addNumber( int begin, int end )
{
	size_t range = std::abs(end) - std::abs(begin);
	
	if (getSum() == getStorage() || range > getStorage())
		throw Span::SpanAlreadyFullException();
	
	for (size_t i = 0; i < range; i++)
	{
		this->_tab->push_back(begin++);
		this->_sum += 1;
	}
	return ;
}

int				Span::shortestSpan( void )
{
	if (getSum() < 2)
		throw Span::SpanNotFilledEnoughException();

	/* It is not a question of finding the two smallest values,
	** but the two closest values to obtain the difference between them */

	int diff = INT_MAX;

	for (size_t next = 0; next < getSum(); next++)
	{
		for (size_t prev = 0; prev < getSum(); prev++)
		{
			//std::cout << "abs next: " << std::abs(_tab->at(next)) << " - ";
			//std::cout << "abs prev: " << std::abs(_tab->at(prev)) << std::endl;
			if (std::abs(_tab->at(next)) - std::abs(_tab->at(prev)) < diff		// If next - prev < largest possible span
				&& std::abs(_tab->at(next)) != std::abs(_tab->at(prev))			// If next is different from prev
					&& std::abs(_tab->at(next)) - std::abs(_tab->at(prev)) > 0) // If next - prev is bigger than 0
			{
				diff = std::abs(_tab->at(next)) - std::abs(_tab->at(prev));
			}
		}
	}
	std::cout << T_BB "The shortest span is: ";
	return (diff);

	
}

int		Span::longestSpan( void )
{
	if (getSum() < 2)
		throw Span::SpanNotFilledEnoughException();
	
	// Finds the greatest element in the range [first, last)
	int	max = *std::max_element(this->_tab->begin(), this->_tab->end());

	// Finds the smallest element in the range [first, last)
	int	min = *std::min_element(this->_tab->begin(), this->_tab->end());

	int ret = std::abs(max - min);
	std::cout << T_BB "The longest span is: ";

	return (ret);
}


// Exceptions

const char* Span::SpanAlreadyFullException::what() const throw()
{
	return (T_Y "The tab is currently unable to store a new entry." T_N);
}

const char* Span::SpanNotFilledEnoughException::what() const throw()
{
	return (T_Y "The tab is currently incomplete to treat a span." T_N);
}

static	void	displayInt( int i );
