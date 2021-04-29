/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:05:04 by salome            #+#    #+#             */
/*   Updated: 2021/04/19 20:28:49 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int		main( void )
{

	//Testing initialization by default
	//int * a = new int();
	//std::cout << *a << std::endl;

	// Testing default constructor without parameter
	Array< int > emptyArray;
	std::cout << T_GYB "Empty array size: " T_BB << emptyArray.size() << T_N << std::endl;
	try
	{
		for (unsigned int i = 0; i < 5; i++)
			std::cout << T_GYB "Int array content: " T_BB << emptyArray[i] << T_N << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;


	// Testing int type
	Array< int >  intArray(8); // Explicit instanciation
	std::cout << T_GYB "Int array size: " T_BB << intArray.size() << T_N << std::endl;
	try
	{
		for (unsigned int i = 0; i < intArray.size(); i++)
			std::cout << T_GYB "Int array content: " T_BB << intArray[i] << T_N << std::endl;
		std::cout << T_GYB "Int array content: " T_BB << intArray[intArray.size() + 1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;


	// Testing string type
	Array< std::string >  stringArray(2); // Explicit instanciation
	std::cout << T_GYB "String array size: " T_BB << stringArray.size() << T_N << std::endl;
	try
	{
		stringArray[0] = "Summer";
		stringArray[1] = "is coming";

		for (unsigned int i = 0; i < stringArray.size(); i++)
			std::cout << T_GYB "String array content: " T_BB << stringArray[i] << T_N << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Testing copy
	try
	{
		Array< std::string > stringCopy(stringArray);

		stringCopy[0] = "Winter";

		for (unsigned int i = 0; i < stringCopy.size(); i++)
			std::cout << T_GYB "String copy array content: " T_BB << stringCopy[i] << T_N << std::endl;
		
		for (unsigned int i = 0; i < stringArray.size(); i++)
			std::cout << T_GYB "String array content: " T_BB << stringArray[i] << T_N << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	// Testing float type
	Array< float >  floatArray(3); // Explicit instanciation
	std::cout << T_GYB "Float array size: " T_BB << floatArray.size() << T_N << std::endl;
	try
	{
		floatArray[0] = 3.141;
		floatArray[1] = 1893.158;
		floatArray[2] = 18.16;
		
		for (unsigned int i = 0; i < floatArray.size(); i++)
			std::cout << T_GYB "Float array content: " T_BB << floatArray[i] << T_N << std::endl;
		std::cout << T_GYB "Float array content: " T_BB << floatArray[floatArray.size() + 1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	// Testing complex class type
	Array< Array < char > >  classArray(4); // Explicit instanciation, calling our Array constructor n times
	std::cout << T_GYB "Class array size: " T_BB << classArray.size() << T_N << std::endl;
	try
	{
		// Remember classArray has been created by default constructor, so it's null
		std::cout << T_GYB "String array content: " T_BB << classArray[0][0] << T_N << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}