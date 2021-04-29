/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:36:00 by salome            #+#    #+#             */
/*   Updated: 2021/04/21 21:16:37 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

/* The std::stack class is a container adapter that gives the programmer 
** the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure. */

/* 	Remember that there are iterators, dedicated for list, vector, map...
**	but not for stack ! */

/* C++ iterators are used for sequential access or random access to elements within the data structure.
** Thus, iterators would have no meaning for data structures that, by definition, don’t allow for sequential or random access.
** That’s why there are no iterators for stacks and queues. 
** On the other hand, vectors and lists allow sequential and/or random access to elements, so iterators 
** make sense for navigating these data structures. */

# define T_N "\033[00m"
# define T_Y "\033[00;33m"
# define T_GN "\033[00;32m"
# define T_GYB "\033[01;90m"
# define T_GYI "\033[03;90m"
# define T_GYHID "\033[2;90m"
# define T_BB "\033[01;34m"

template< typename T >
class MutantStack : public std::stack<T> // MutantStack has the std::stack behavior
{
	private:

	public:
		MutantStack<T>( void ) : std::stack<T>()
		{
			std::cout << T_GYHID "Default constructor called" T_N << std::endl;
		};
		MutantStack<T>( MutantStack const &src ) : std::stack<T>(src) {};
		MutantStack<T> &operator=( MutantStack const &rhs ) 
		{
			std::stack<T>::operator=(rhs);
		};
		virtual ~MutantStack<T>( void )
		{
			std::cout << T_GYHID "Destructor called" T_N << std::endl;
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin() 
		{ 
			return ( std::stack<T>::c.begin() ); 
		}
        const_iterator begin() const 
		{ 
			return ( std::stack<T>::c.begin() ); 
		}
        iterator end() 
		{ 
			return ( std::stack<T>::c.end() ); 
		}
        const_iterator end() const 
		{ 
			return ( std::stack<T>::c.end() ); 
		}
        reverse_iterator rbegin() 
		{
			return ( std::stack<T>::c.rbegin() );
		}
        const_reverse_iterator rbegin() const
		{
			return ( std::stack<T>::c.rbegin() );
		}
        reverse_iterator rend()
		{
			return ( std::stack<T>::c.rend() );
		}
        const_reverse_iterator rend() const 
		{
			return ( std::stack<T>::c.rend() );
		}
};

#endif