/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:28:24 by salome            #+#    #+#             */
/*   Updated: 2021/04/17 21:47:51 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void	*serialize( void )
{
	std::cout << T_GN "Serializing data process..." T_N << std::endl;
	Data *processed = new Data;

	// Our ref to generate 8 random alphanumeric caracters in s1 and s2
	std::string alphnum = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	size_t size = alphnum.length();
	
	// Random s1
	for (int i = 0; i < 8; i++)
		processed->s1 += alphnum[rand() % size];

	// Random int
	processed->n = rand() % 100;

	// Random s2
	for (int i = 0; i < 8; i++)
		processed->s2 += alphnum[rand() % size];

	return (reinterpret_cast<void*>(processed)); // ([return] automatically apply the cast but...)
}

Data	*deserialize( void *raw )
{
	std::cout << T_GN "Deserializing data process...\n" T_N << std::endl;
	return (reinterpret_cast<Data*>(raw));
}

int		main( void )
{
	srand(time(NULL));

	std::cout << T_BB "\n\t\tLet's discover serialization...\n" T_N << std::endl;

	void *serializedData = serialize(); 					// Generating a void*
	Data *deserializedData = deserialize( serializedData ); // Generating a Data*

	std::cout << T_GYB "Our first random string: \t" T_BB;
	std::cout << deserializedData->s1 << T_N << std::endl;

	std::cout << T_GYB "Our random integer: \t\t" T_BB;
	std::cout << deserializedData->n << T_N << std::endl;

	std::cout << T_GYB "Our second random string: \t" T_BB;
	std::cout << deserializedData->s2 << T_N << std::endl << std::endl;

	std::cout << T_GN "Serialized data gives: \t\t" T_BB << serializedData << T_N << std::endl;
	std::cout << T_GN "Deserialized data gives: \t" T_BB;
	std::cout << deserializedData->s1 << deserializedData->n << deserializedData->s2 << T_N << std::endl;

	delete deserializedData;
	return (0);
}