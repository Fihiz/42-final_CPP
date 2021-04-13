/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poobook.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:17:17 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/17 23:36:48 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POOBOOK_CLASS_HPP
# define POOBOOK_CLASS_HPP

#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

class Poobook
{
private:
    
    Contact	_contact[8];
	int		_contactSum;

public:

    Poobook( void );
    ~Poobook( void );
	void	welcomeDisplayer( void );
    void	setPoobookFiller( void );
	void	getPoobookSearcher( void );
	void	getPoobookDisplayer( void );

};

#endif