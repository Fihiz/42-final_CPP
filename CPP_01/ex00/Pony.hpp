/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:32:13 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/22 16:29:25 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

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

class Pony
{
private:
    std::string	_ponyName;
	std::string	_ponyBreed;
	std::string	_ponySize;
	std::string	_ponyCoat;

public:
	//Default Constructor ?
    Pony( std::string const, std::string const, std::string const );
    ~Pony( void );

	void	getPonyStackInfos( void ) const; //Statically allocated
	void	getPonyStackActions ( int, int ) const;

	void	getPonyHeapInfos( void ) const; //Dynamically allocated
	void	getPonyHeapActions ( int, int ) const;
};

#endif