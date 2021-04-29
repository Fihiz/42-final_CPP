/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 00:06:31 by salome            #+#    #+#             */
/*   Updated: 2021/04/17 22:09:30 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


// Infinity checker
int		is_inff_nanf( std::string arg )
{
	if (arg == "-inff" || arg == "+inff" || arg == "nanf")
		return (1);
	return (0);
}

int		is_inf_nan( std::string arg )
{
	if (arg == "-inf" || arg == "+inf" || arg == "nan")
		return (1);
	return (0);
}


// Types converter
void	to_char_converter( std::string arg, double departure )
{
	std::cout << T_GYB "char: ";
	if (is_inff_nanf(arg) || is_inf_nan(arg))
		std::cout << T_BB "impossible" T_N << std::endl;
	else if (isprint(departure))
		std::cout << "'" T_BB << static_cast<char>(departure) << T_GYB "'" T_N << std::endl;
	else
		std:: cout << T_BB "Non displayable" T_N << std::endl;
}

void	to_int_converter( std::string arg, double departure )
{
	std::cout << T_GYB "int: " T_BB;
	if (is_inff_nanf(arg) || is_inf_nan(arg))
		std::cout << T_BB "impossible" T_N << std::endl;
	else
		std::cout << static_cast<int>(departure) << T_N << std::endl;
}

// Precision checker for double and float
int		to_get_prec( std::string arg )
{
	int set = 0;
	int prev = arg.find(".");

	if (prev >= 0 && arg[prev + 1])
	{
		std::string trunc = arg.substr(prev + 1, arg.length());
		for (int prec = 0; (prec < static_cast<int>(trunc.length()) && trunc[prec + 1] != 'f'); prec++)
			set = prec + 1;
	}
	return (set);
}

void	to_float_converter( std::string arg, double departure )
{
	std::cout << T_GYB "float: " T_BB;
	if (arg == "nanf")
		std::cout << T_BB "nanf" T_N << std::endl;
	else if (arg == "-inff")
		std::cout << T_BB "-inff" T_N << std::endl;
	else if (arg == "+inff")
		std::cout << T_BB "inff" T_N << std::endl;
	else
	{
		int set = to_get_prec( arg );
		if (set > 0)
		{
			if (arg[arg.length() - 1] == 'f')
				set += 1;
			std::cout << std::fixed << std::setprecision(set) << static_cast<double>(departure) << "f" << T_N << std::endl;
		}
		else
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(departure) << "f" << T_N << std::endl;
	}
}

void	to_double_converter( std::string arg, double departure )
{
	std::cout << T_GYB "double: " T_BB;
	if (arg == "nan")
		std::cout << T_BB "nan" T_N << std::endl;
	else if (arg == "-inf" || arg == "-inff")
		std::cout << T_BB "-inf" T_N << std::endl;
	else if (arg == "+inf" || arg == "+inff")
		std::cout << T_BB "inf" T_N << std::endl;
	else
	{
		int set = to_get_prec( arg );
		if (set > 0)
		{
			if (arg[arg.length() - 1] == 'f')
				set += 1;
			std::cout << std::fixed << std::setprecision(set) << static_cast<double>(departure) << T_N << std::endl;
		}
		else
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(departure) << T_N << std::endl;
	}
}


// Starting argument checker
int		is_char( std::string arg)
{
	if (arg.length() == 1)
		if (isprint(arg[0]) && !isdigit(arg[0]))
			return (1);
	return (0);
}

int		is_int( std::string arg )
{
	unsigned long i = 0;

	if (arg[i] == '-' || arg[i] == '+')
		i += 1;
	for (unsigned long ind = i; ind < arg.length(); ind++)
	{
		if (arg[ind] >= '0' && arg[ind] <= '9')
			i++;
	}
	if (i == arg.length())
		return (1);
	return (0);
}

int		is_double_or_float( std::string arg )
{
	int check = 0;
	if (isdigit(arg[0]) || arg[0] == '-' || arg[0] == '+')
		check += 1;
	if (isdigit( arg[arg.length() - 1] ) ||  arg[arg.length() - 1] == 'f'
		||  arg[arg.length() - 1] == '.' || arg[arg.length() - 1] == ',')
		check += 1;

	int found = 0;
	for (unsigned long ind = 0; ind < arg.length(); ind++)
	{
		if (arg[ind] == '.' || arg[ind] == ',')
			found += 1;
	}
	if (found == 1)
		check += 1;
	
	if (is_inf_nan(arg) || is_inff_nanf(arg) || check == 3)
		return (1);
	return (0);
}	


// Error displaying manager
int error_managing( int error )
{
	if (error == -1)
		std::cout << T_Y "Error: Please try again with only one argument." T_N << std::endl;
	else if (error == -2)
		std::cout << T_Y "Error: This literal must belong to one of the following a scalar types: char, int, float or double. " T_N << std::endl;
	return (-1);
}


// Main part
int		main( int ac, char **av )
{
	// Remember the picture of putting an elephant in a mouse
	double departure = 0.0; // I need to catch the starting literal type in the biggest bytes capacity
	if (ac == 2 && static_cast<std::string>(av[1]).length() > 0)
	{
		if (is_char(av[1]))
			departure = av[1][0];
		else if ( is_int(av[1]) || is_double_or_float(av[1]))
			departure = std::atof(av[1]);
		else
			return (error_managing(-2));
		to_char_converter( av[1], departure );
		to_int_converter( av[1], departure );
		to_float_converter( av[1], departure );
		to_double_converter( av[1], departure );
	}
	else
		return (error_managing(-1));
	return (0);
}
