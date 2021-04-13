/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:23:59 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 11:01:15 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMAN_HPP
# define HUMAN_HPP

#include <iostream>
#include <sstream>
#include "Brain.hpp"

class Human
{
	private:
		const Brain _humanBrain; // Constant brain attribute

	public:
		Human( void );
		~Human( void );

		const Brain	&getBrain( void ) const; // Returns the brain reference

		const std::string	identify( void ) const;
};

#endif