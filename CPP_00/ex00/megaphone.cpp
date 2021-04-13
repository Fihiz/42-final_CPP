/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:48:50 by sad-aude          #+#    #+#             */
/*   Updated: 2021/03/16 11:53:05 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int     main(int ac, char **av)
{
    int i = 1;

    if (ac > 1)
    {
        while (av[i])
        {
            std::string str = av[i];
            std::transform(str.begin(), str.end(), str.begin(), toupper);
            std::cout << "" << str;
            i++;
        }
    }
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}