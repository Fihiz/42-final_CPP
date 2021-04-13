/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:08:37 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/17 23:34:36 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Poobook.class.hpp"
#include "include/Contact.class.hpp"

int     main()
{
    Poobook instPoobook;
    std::string input;

	instPoobook.welcomeDisplayer();
	std::cout << T_GYB "ENTRY_ " T_N;
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
			instPoobook.setPoobookFiller();
		else if (input == "SEARCH")
			instPoobook.getPoobookSearcher();
		else if (input == "EXIT")
		{
			std::cout << T_GYB "\t\tTHANK YOU FOR USING POOBOOK !" T_N << std::endl;
            break ;
		}
		std::cout << T_GYB "ENTRY_ " T_N;
	}
    return (0);
}