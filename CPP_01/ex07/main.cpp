/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:29:54 by salome            #+#    #+#             */
/*   Updated: 2021/03/22 20:12:53 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

# define CLEAN "\e[1;1H\e[2J"
# define T_N "\033[00m"
# define T_YB "\033[2;33m"
# define T_GNB "\033[01;32m"
# define T_GYB "\033[01;90m"
# define T_GY "\033[00;90m"
# define T_BB "\033[01;34m"
# define T_BHID "\033[2;34m"
# define T_GYHID "\033[2;34m"
# define T_CB "\033[01;36m"
# define T_RB "\033[01;31m"
# define T_R "\033[00;31m"

int		error_manager(int error)
{
	if (error == 1)
	{
		std::cout << T_RB "An error occured.\nWe need three valid arguments to make our programm a success." << std::endl;
		std::cout << T_CB "Try again like_ > [./replace -filename- -s1- -s2-]" T_N << std::endl;
	}
	else if (error == 2)
	{
		std::cout << T_RB "An error occured.\nStrings arguments are corrupted.";
		std::cout << " Try again with non null ones." << std::endl;
	}
	else if (error == 3)
	{
		std::cout << T_RB "An error occured.\nThe file you gave is actually unexistant.";
		std::cout << " Try again with an existing one." << std::endl;
	}
	else if (error == 4)
	{
		std::cout << T_RB "An error occured.\nThe [file].replace creation failed.";
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string file = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		
		if (file.empty() || s1.empty() || s2.empty())
			return (error_manager(2));
		else
		{
			//Settling current stream on source file
			std::ifstream  ifs(file); 			// Input file stream, opening our stream

			if (!ifs.good()) 					// Returns false if one of the stream's error state flags is set
				return (error_manager(3));
			
			std::stringstream line; 			// Constructs a stringstream object with an empty sequence as content
			line << ifs.rdbuf(); 				// Returns a pointer to the stream buffer object currently associated with the stream

			std::string str = line.str(); 		// Returns a string object with a copy of the current contents of the stream
			
			size_t start_pos = 0;
    		while((start_pos = str.find(s1, start_pos)) != std::string::npos) 
			{
				str.replace(start_pos, s1.length(), s2);
       			start_pos += s2.length(); 		// In case 's2' contains 's2', like replacing 'x' with 'yx'
			}
			ifs.close();

			//Settling current stream on file.replace creation
			std::ofstream ofs(file + ".replace"); //Output file stream, create [file].replace
			if (!ofs.good())
				return (error_manager(4));
			ofs << str; 						//Redirecting our modified str into output file stream
			ofs.close();
		}
	}
	else
		return (error_manager(1));
	return (0);
}