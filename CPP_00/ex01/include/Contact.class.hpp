/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:47:16 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/17 23:36:17 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# define CLEAN "\e[1;1H\e[2J"
# define T_N "\033[00m"
# define T_YB "\033[2;33m"
# define T_GNB "\033[01;32m"
# define T_GYB "\033[01;90m"
# define T_BB "\033[01;34m"
# define T_CB "\033[01;36m"
# define T_RB "\033[01;31m"

#include <iostream>
#include <iomanip>

class Contact
{
private:

    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _login;
    std::string _postalAddress;
    std::string _emailAddress;
    std::string _phoneNumber;
    std::string _birthdayDate;
    std::string _favoriteMeal;
    std::string _underwearColor;
    std::string _darkestSecret;
	int		_infoSum;

public:
    Contact( void );
    ~Contact( void );
    int		setContactInfos( void );
	void	getContactInfosDisplayer( int index ); 
	void	setContactFormatDisplayer( std::string line);
	void	getContactFullDisplayer( void ) const;

};

#endif