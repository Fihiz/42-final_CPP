/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poobook.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:02:17 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/17 23:52:26 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Poobook.class.hpp"

Poobook::Poobook( void )
{
	this->_contactSum = 0;
    return;
}

Poobook::~Poobook( void )
{
    return;
}

void	Poobook::welcomeDisplayer( void )
{
    std::cout << std::endl;
    std::cout << T_GYB "\t\tPLEASE BE WELCOME ON..." << std::endl;
    std::cout << std::endl;

    std::cout << T_CB "888 88e    e88 88e     e88 88e   888 88b,   e88 88e     e88 88e   888 88P" << std::endl; 
    std::cout << "888 888D  d888 888b   d888 888b  888 88P'  d888 888b   d888 888b  888 8P" << std::endl;
    std::cout << "888 88\"  C8888 8888D C8888 8888D 888 8K   C8888 8888D C8888 8888D 888 K" << std::endl; 
    std::cout << "888       Y888 888P   Y888 888P  888 88b,  Y888 888P   Y888 888P  888 8b" << std::endl; 
    std::cout << "888        \"88 88\"     \"88 88\"   888 88P\'   \"88 88\"     \"88 88\"   888 88b" T_N << std::endl;
    std::cout << std::endl;

    std::cout << T_GYB "\tHere lies your own Poobook (poo...POO...book)." << std::endl;
    std::cout << "\tFeel free to add until 8 contacts (not more friends, sorry!)." <<std::endl;
    std::cout << "\tFor it, you can use the below commands in capital letters:" <<std::endl;
    std::cout << std::endl;
	
    std::cout << T_CB "\n\t\t1. ADD" <<std::endl;
    std::cout << "\t\t2. SEARCH" <<std::endl;
    std::cout << "\t\t3. EXIT" T_N <<std::endl;
    std::cout << std::endl;
}

void	Poobook::setPoobookFiller ( void )
{
	if (this->_contactSum == 8)
	{
		std::cout << T_RB "Your POOBOOK is full. ";
		std::cout << "No more than 8 friends my dear... You'll have to relaunch PooBook!" T_N << std::endl;
		return ;
	}
	if (this->_contact[this->_contactSum].setContactInfos())
		this->_contactSum++;
	else
		std::cout << T_RB "An empty field is invalid. Contact could'nt be created." T_N << std::endl;
}

void	Poobook::getPoobookDisplayer ( void )
{
	int	index = 0;
	std::cout << T_CB << std::setfill('_') << std::setw(45) << "\n" << std::endl;;
	std::cout << "|    INDEX |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	std::cout << std::setfill('_') << std::setw(45) << "" << std::endl;;
	while (index < this->_contactSum)
	{
		this->_contact[index].getContactInfosDisplayer(index);
		index++;
	}
}

void	Poobook::getPoobookSearcher ( void )
{
	if (this->_contactSum == 0)
	{
		std::cout << T_RB "Your POOBOOK seems empty... ";
		std::cout << "Please add a contact using [ADD] command." T_N << std::endl;
		return ;
	}

	Poobook::getPoobookDisplayer();

	std::cout << T_GYB "\nYou can now give me an index (from 0 to 7) ";
	std::cout << "and I'll tell you who your friend is !" T_N << std::endl;
	std::cout << T_GYB "ENTRY INDEX_ " T_N;

	std::string input;
	std::getline(std::cin, input);
	if (input.length() != 1)
	{
		std::cout << T_RB "Nop! Something went wrong... Please try again with [SEARCH]" T_N << std::endl;
		return;
	}
	if (input[0] >= '0' && input[0]<= '7')
	{
		int number = std::atoi(input.c_str());
		if (number >= 0 && number <= 7)
		{
			if (number < this->_contactSum)
				this->_contact[number].getContactFullDisplayer();
			else
				std::cout << T_RB"Well, there is obviously no friend created at this index yet !" << std::endl;
		}
	}
	else
		std::cout << T_RB"Nop! Index is corrupted... Please try again with [SEARCH]" << std::endl;
}
