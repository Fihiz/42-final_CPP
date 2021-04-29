/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:35:54 by salome            #+#    #+#             */
/*   Updated: 2021/04/21 21:11:41 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
	
int main()
{
	MutantStack<int> mstack;
	
	std::cout << T_GN "\nFilling mstack" T_N << std::endl;
	mstack.push(5); // Inserts a new element at the top of the stack, above its current top element
	mstack.push(17);

	std::cout << T_GN "\nChecking mstack size and top" T_N << std::endl;
	std::cout << T_GYB "mstack current size: " T_BB << mstack.size() << std::endl;
	std::cout << T_GYB "mstack top: " T_BB << mstack.top() << std::endl; // The top element is the last element inserted into the stack
	
	std::cout << T_GN "\nRemoving last entered element" T_N << std::endl;
	mstack.pop(); // Removes the element on top of the stack, effectively reducing its size by one
	std::cout << T_GYB "mstack top: " T_BB << mstack.top() << std::endl;
	std::cout << T_GYB "mstack current size: " T_BB << mstack.size() << std::endl;
	
	std::cout << T_GN "\nFilling mstack" T_N << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(18);
	
	// Now declaring mstack iterators
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it; // Now [it] is 3 (begin + 1)
	//std::cout << "it++: " << *it << std::endl;
	--it; // Now [it] is on the top again
	//std::cout << "it--: " << *it << std::endl;
	//std::cout << std::endl;

	std::cout << T_GN "\nIterating on mstack" T_N << std::endl;
	while (it != ite)
	{
		std::cout << T_GYB "mstack: " T_BB << *it << std::endl;
		++it;
	}

	// Now declaring mstack reverse iterators
	MutantStack<int>::reverse_iterator it1 = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite1 = mstack.rend();

	std::cout << T_GN "\nReverse iterating on mstack" T_N << std::endl;
	while (it1 != ite1)
	{
		std::cout << T_GYB "mstack reverse: " T_BB << *it1 << std::endl;
		++it1;
	}

	// Testing std::stack template object
	std::cout << T_GN "\nTesting s std::stack object, taking mstack's stack" T_N << std::endl;
	std::stack<int> s(mstack); // Taking MutantStack stack
	std::cout << T_GYB "s top: " T_BB << s.top() << std::endl;

	std::cout << T_GYB "mstack current size: " T_BB << mstack.size() << std::endl;
	std::cout << T_GYB "s current size: " T_BB << mstack.size() << std::endl;

	// Would not compile
	//std::stack<int>::reverse_iterator it2 = mstack.rbegin();
	//std::stack<int>::reverse_iterator ite2 = mstack.rend();

	return 0;
}

// Testing: clang++ -Wall -Wextra -Werror main.cpp