/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:15:40 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 11:11:36 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Human.hpp"

Human::Human( void )
{
	std::cout << T_BB "Human Constructor called" T_N << std::endl;
    return;
}

Human::~Human( void )
{
	std::cout << T_BB "Human Destructor called" T_N << std::endl;
    return;
}

const Brain &Human::getBrain( void ) const
{
	return (this->_humanBrain); //Points on my instance, return a const ref it
}

const std::string	Human::identify( void ) const
{
	return (this->_humanBrain.identify()); //Calls humanBrain identify method, returns its pointer
}