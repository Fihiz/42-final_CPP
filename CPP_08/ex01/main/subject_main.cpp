/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:41:53 by salome            #+#    #+#             */
/*   Updated: 2021/04/21 12:14:32 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../span.hpp"

int		main( void )
{
	Span sp = Span(5);
	
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return (0);
}

// Testing: clang++ -Wall -Wextra -Werror main/subject_main.cpp span.cpp
