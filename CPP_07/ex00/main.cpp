/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 00:59:08 by salome            #+#    #+#             */
/*   Updated: 2021/04/19 19:28:33 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int		main( void ) 
{
	std::cout << T_GN "Testing int type" T_N << std::endl;
	int a = 2;
	int b = 3;

	swap( a, b ); // Calling our swap template
	std::cout << T_GYB "a = " T_BB << a << T_GYB ", b = " T_BB << b << std::endl;
	std::cout << "a: " << &a << std::endl;
	std::cout << "b: " << &b << std::endl;
	std::cout << T_GYB "min( a, b ) = " T_BB << min( a, b ) << " (" << &min( a, b ) << ")" << std::endl; // Calling our min template
	std::cout << T_GYB "max( a, b ) = " T_BB << max( a, b ) << " (" << &max( a, b ) << ")" << T_N << std::endl; // Calling our max template
	std::cout << std::endl;

	std::cout << T_GN "Testing equal int type" T_N << std::endl;
	int a1 = 2101;
	int b1 = 2101;

	swap( a1, b1 ); // Calling our template
	std::cout << T_GYB "a1 = " T_BB << a1 << T_GYB ", b1 = " T_BB << b1 << std::endl;
	std::cout << T_GYI "If args are equal, I may return the second one " T_N T_BB << std::endl;
	std::cout << "a1: " << &a1 << std::endl;
	std::cout << "b1: " << &b1 << std::endl;
	std::cout << T_GYB "min( a1, b1 ) = " T_BB << min( a1, b1 ) << " (" << &min( a1, b1 ) << ")" << std::endl;
	std::cout << T_GYB "max( a1, b1 ) = " T_BB << max( a1, b1 ) << " (" << &max( a1, b1 ) << ")" T_N << std::endl;
	std::cout << std::endl;
	
	std::cout << T_GN "Testing string type" T_N << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	swap(c, d);
	std::cout << T_GYB "c = " T_BB << c << T_GYB ", d = " T_BB << d << std::endl;
	std::cout << "c: " << &c << std::endl;
	std::cout << "d: " << &d << std::endl;
	std::cout << T_GYB "min( c, d ) = " T_BB << min( c, d ) << " (" << &min( c, d ) << ")" << std::endl;
	std::cout << T_GYB "max( c, d ) = " T_BB << max( c, d ) << " (" << &max( c, d ) << ")" T_N << std::endl;
	std::cout << std::endl;

	std::cout << T_GN "Testing char type" T_N << std::endl;
	char c1 = '#';
	char d1 = '*';
	
	swap(c1, d1);
	std::cout << T_GYB "c1 = " T_BB << c1 << T_GYB ", d1 = " T_BB << d1 << std::endl;
	std::cout << T_GYB "min( c1, d1 ) = " T_BB << min( c1, d1 ) << std::endl;
	std::cout << T_GYB "max( c1, d1 ) = " T_BB << max( c1, d1 ) << T_N << std::endl;
	std::cout << std::endl;

	std::cout << T_GN "Testing float type" T_N << std::endl;
	float e = 3.141;
	float f = 3.142;
	
	swap(e, f);
	std::cout << T_GYB "e = " T_BB << e << T_GYB ", f = " T_BB << f << std::endl;
	std::cout << "e: " << &e << std::endl;
	std::cout << "f: " << &f << std::endl;
	std::cout << T_GYB "min( e, f ) = " T_BB << min( e, f ) << " (" << &min( e, f ) << ")" << std::endl;
	std::cout << T_GYB "max( e, f ) = " T_BB << max( e, f ) << " (" << &max( e, f ) << ")" T_N << std::endl;
	std::cout << std::endl;

	std::cout << T_GN "Testing class type" T_N << std::endl;
	int one = 23;
	int two = 45;
	ComplexType inst1 = ComplexType(one);
	ComplexType inst2 = ComplexType(two);

	std::cout << T_BB "inst1: " << &inst1 << std::endl;
	std::cout << "inst2: " << &inst2 << std::endl;
	
	::swap(inst1, inst2);
	std::cout << T_GYB "min( inst1, inst2 ) = " T_BB << &min( inst1, inst2 ) << std::endl;
	std::cout << T_GYB "max( inst1, inst2 ) = " T_BB << &max( inst1, inst2 ) << T_N << std::endl;
	std::cout << std::endl;

	std::cout << T_GN "Testing equal class type" T_N << std::endl;
	ComplexType inst3 = ComplexType(1000);
	ComplexType inst4 = ComplexType(1000);

	std::cout << T_BB "inst3: " << &inst3 << std::endl;
	std::cout << "inst4: " << &inst4 << std::endl;
	
	swap(inst3, inst4);
	std::cout << T_GYB "min( inst3, inst4 ) = " T_BB << &min( inst3, inst4 ) << std::endl;
	std::cout << T_GYB "max( inst3, inst4 ) = " T_BB << &max( inst3, inst4 ) << T_N << std::endl;
	std::cout << std::endl;
	
	return (0);
}