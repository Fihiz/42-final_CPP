/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:32:10 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/22 16:29:38 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

// Constructor and Destructor
Pony::Pony(std::string ponyName, std::string ponyBreed, std::string ponyCoat) 
		: _ponyName(ponyName), _ponyBreed(ponyBreed), _ponyCoat(ponyCoat)
{
    std::cout << T_BB "Pony Constructor called" T_N << std::endl;
    return;
}

Pony::~Pony( void )
{
    std::cout << T_BB "Pony Destructor called" T_N << std::endl;
    return;
}

// Getters
void	Pony::getPonyStackInfos( void ) const
{
	std::cout << T_CB "\nLet's discover my Pony on the Stack (means statically allocated)" << std::endl;
	std::cout << T_GYB << "My ponyStack name is_ " << T_CB << this->_ponyName << std::endl;
	std::cout << T_GYB << "My ponyStack breed is_ " << T_CB << this->_ponyBreed << std::endl;
	std::cout << T_GYB <<"My ponyStack coat is_ " << T_CB << this->_ponyCoat << std::endl;
}

void	Pony::getPonyStackActions( int jump, int rest ) const
{
	std::cout << std::endl;
	std::cout << T_CB "Now let's take care of my Pony on the Stack" << std::endl;
	std::cout << T_GYB "Let " << T_CB << this->_ponyName << T_GYB " do " << T_CB << jump << T_GYB " jumps !" << std::endl;
	std::cout << "1... 2... " << T_CB << jump << T_GYB << " !" T_N <<  std::endl;
	std::cout  << T_GYB "All right, let brush our pony's beautiful " << T_CB << this->_ponyCoat << T_GYB " coat !" << std::endl;
	std::cout << T_GYB "... *BRSSSH* ... *BRSSSH* " << std::endl;
	std::cout << T_GYB "It's nap time now... let my " << T_CB << this->_ponyName << T_GYB << " rest for " << T_CB << rest << T_GYB " minutes...\n" << std::endl;
}

void	Pony::getPonyHeapInfos( void ) const
{
	std::cout << T_CB "\nLet's discover my Pony on the Heap (means dynamically allocated)" << std::endl;
	std::cout << T_GYB << "My ponyStack name is_ " << T_CB << this->_ponyName << std::endl;
	std::cout << T_GYB << "My ponyStack breed is_ " << T_CB << this->_ponyBreed << std::endl;
	std::cout << T_GYB <<"My ponyStack coat is_ " << T_CB << this->_ponyCoat << std::endl;
}

void	Pony::getPonyHeapActions( int jump, int rest ) const
{
	std::cout << std::endl;
	std::cout << T_CB "Now let's take care of my pony on the Heap" << std::endl;
	std::cout << T_GYB "Let " << T_CB << this->_ponyName << T_GYB " do " << T_CB << jump << T_GYB " jumps !" << std::endl;
	std::cout << "1... 2... 3... come on.. 4... yeah " << T_CB << jump << T_GYB << " !" T_N <<  std::endl;
	std::cout  << T_GYB "All right, let brush our pony's beautiful " << T_CB << this->_ponyCoat << T_GYB " coat !" << std::endl;
	std::cout << T_GYB "... *BRSSSH* ... *BRSSSH* " << std::endl;
	std::cout << T_GYB "It's nap time now... let my " << T_CB << this->_ponyName << T_GYB << " rest for " << T_CB << rest << T_GYB " minutes...\n" << std::endl;
}