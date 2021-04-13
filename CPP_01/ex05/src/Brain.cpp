/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:15:38 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 11:05:34 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain( void )
{
	std::cout << T_BB "Brain Constructor called" T_N << std::endl;
	this->_brainAge = 35;
	this->_brainIQ = 134;
    return;
}

Brain::~Brain( void )
{
	std::cout << T_BB "Brain Destructor called" T_N << std::endl;
    return;
}

//void	Brain::setBrainCaracteristics(std::string weight, std::string age, std::string IQ)
//{
//	this->_brainWeight = weight;
//	this->_brainAge = age;
//	this->_brainIQ = IQ;
//}

std::string	Brain::identify( void ) const
{
	std::stringstream addressPtr; //Opening our stream to make a string representation of the address
	addressPtr << (void const*) this; //[this] pointing on our Brain object
	return (addressPtr.str());
}