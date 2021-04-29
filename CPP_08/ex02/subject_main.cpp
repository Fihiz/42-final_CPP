/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:19:39 by salome            #+#    #+#             */
/*   Updated: 2021/04/21 21:08:35 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main()
{
	std::cout << T_GN "\nMutantStack" T_N << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;

	std::cout << T_GN "\nList" T_N << std::endl;
	std::list<int> lstack;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << lstack.back() << std::endl;
	lstack.pop_back();
	std::cout << lstack.size() << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);
	std::list<int>::iterator it1 = lstack.begin();
	std::list<int>::iterator ite1 = lstack.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
	std::cout << *it1 << std::endl;
	++it1;
	}
	std::list<int> l(lstack);
	return 0;
}

// Testing: clang++ -Wall -Wextra -Werror subject_main.cpp
