/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:21:00 by salome            #+#    #+#             */
/*   Updated: 2021/04/08 19:51:48 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ISquad.hpp"
#include "../include/Squad.hpp"
#include "../include/ISpaceMarine.hpp"
#include "../include/TacticalMarine.hpp"
#include "../include/AssaultTerminator.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	return 0;
}

// Output

//$> clang++ -W -Wall -Werror *.cpp
//$> ./a.out | cat -e
//Tactical Marine ready for battle!$
//* teleports from space *$
//For the holy PLOT!$
//* attacks with a bolter *$
//* attacks with a chainsword *$
//This code is unclean. PURIFY IT!$
//* does nothing *$
//* attacks with chainfists *$
//Aaargh...$
//I'll be back...$

//Be thorough when you’re making the main function that you will turn in to get your
//grade...