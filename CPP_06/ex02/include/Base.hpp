/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:33:22 by salome            #+#    #+#             */
/*   Updated: 2021/04/17 18:47:17 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <time.h>

# define T_N "\033[00m"
# define T_Y "\033[00;33m"
# define T_GN "\033[00;32m"
# define T_GYB "\033[01;90m"
# define T_BB "\033[01;34m"

class Base
{
	public:
		virtual ~Base() {};
};

#endif