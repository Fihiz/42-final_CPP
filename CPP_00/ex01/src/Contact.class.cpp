/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:58:18 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/18 00:07:03 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.class.hpp"

Contact::Contact( void )
{
    return;
}

Contact::~Contact( void )
{
	this->_infoSum = 0;
    return;
}

void	Contact::getContactFullDisplayer( void ) const
{
	std::cout << T_GYB "\tPlease find all the infos below!" << std::endl;
	std::cout << T_CB << "FIRST NAME_ " << T_GYB << _firstName << std::endl;
	std::cout << T_CB << "LAST NAME_ " << T_GYB << _lastName << std::endl;
	std::cout << T_CB <<"NICKNAME_ " << T_GYB <<_nickname << std::endl;
	std::cout << T_CB <<"LOGIN_ " << T_GYB <<_login << std::endl;
	std::cout << T_CB <<"POSTAL ADDRESS_ " << T_GYB <<_postalAddress << std::endl;
	std::cout << T_CB <<"EMAIL ADDRESS_ " << T_GYB <<_emailAddress << std::endl;
	std::cout << T_CB <<"PHONE NUMBER_ " << T_GYB <<_phoneNumber << std::endl;
	std::cout << T_CB <<"BIRTHDAY DATE_ " << T_GYB <<_birthdayDate << std::endl;
	std::cout << T_CB <<"FAVORITE MEAL_ " << T_GYB <<_favoriteMeal << std::endl;
	std::cout << T_CB <<"UNDERWEAR COLOR_ " << T_GYB <<_underwearColor << std::endl;
	std::cout << T_CB <<"DARKEST SECRET_ " << T_GYB <<_darkestSecret << std::endl;
}

void	Contact::setContactFormatDisplayer ( std::string line )
{
	std::cout << "|";
	if (line.length() > 10)
		std::cout <<line.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << line;
}

void	Contact::getContactInfosDisplayer( int index )
{
	std::cout << "|" << std::setw(10) << index;
	setContactFormatDisplayer(_firstName);
	setContactFormatDisplayer(_lastName);
	setContactFormatDisplayer(_nickname);
	std::cout << "|" << std::endl;
}

int    Contact::setContactInfos( void )
{
	std::string	info;
	this->_infoSum = 0;
	
    std::cout << T_GYB "\tPlease let me know about..." T_N << std::endl;
	
	std::cout << T_CB "FIRST NAME_ " T_N;
	if (std::getline(std::cin, info) && !info.empty())
	{
		_firstName = info;
		this->_infoSum++;
	}
	
	std::cout << T_CB "LAST NAME_ " T_N;
	if (std::getline(std::cin, info) && !info.empty())
	{
		_lastName = info;
		this->_infoSum++;
	}

	std::cout << T_CB "NICKNAME_ " T_N;
	if (std::getline(std::cin, info) && !info.empty())
	{
		_nickname = info;
		this->_infoSum++;
	}

	std::cout << T_CB "LOGIN_ " T_N;
	if (std::getline(std::cin, info) && !info.empty())
	{
		_login = info;
		this->_infoSum++;
	}

	std::cout << T_CB "POSTAL ADDRESS_ " T_N;
	if (std::getline(std::cin, info) && !info.empty())
	{
		_postalAddress = info;
		this->_infoSum++;
	}

	std::cout << T_CB "EMAIL ADDRESS_ " T_N;
	if (std::getline(std::cin, info) && !info.empty())
	{
		_emailAddress = info;
		this->_infoSum++;
	}

	std::cout << T_CB "PHONE NUMBER_ " T_N;
	if (std::getline(std::cin, info) && !info.empty())
	{
		_phoneNumber = info;
		this->_infoSum++;
	}

	std::cout << T_CB "BIRTHDAY DATE_ " T_N;
	if (std::getline(std::cin, info) && !info.empty())
	{
		_birthdayDate = info;
		this->_infoSum++;
	}

	std::cout << T_CB "FAVORITE MEAL_ " T_N;
	if (std::getline(std::cin, info) && !info.empty())
	{
		_favoriteMeal = info;
		this->_infoSum++;
	}

	std::cout << T_CB "UNDERWEAR COLOR_ " T_N;
	if (std::getline(std::cin, info) && !info.empty())
	{
		_underwearColor = info;
		this->_infoSum++;
	}

	std::cout << T_CB "DARKEST SECRET_ " T_N;
	if (std::getline(std::cin, info) && !info.empty())
	{
		_darkestSecret = info;
		this->_infoSum++;
	}

	if (this->_infoSum < 11)
		return (0);
	std::cout << T_GNB "Contact has been created ! You can now look for it." T_N << std::endl;
	return (1);
}
