/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:50:43 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/14 17:44:33 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

// COPLIEN FORM

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target ) :
	AForm("Schrubbery Creation Form", 145, 137)
{
	setTarget(target);
	std::cout << T_GYHID "ShrubberyCreationForm Name and Grade constructor called,";
	std::cout << " having " << getTarget() << " for target" << T_N << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src ) :
	AForm(src)
{
	std::cout << T_GYHID "ShrubberyCreationForm Copy constructor called" T_N << std::endl;
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs )
{
	std::cout << T_GYHID "ShrubberyCreationForm Assignation operator overload called" T_N << std::endl;
	rhs.getName();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << T_GYHID "ShrubberyCreationForm destructor called" T_N << std::endl;
	return ;
}

// METHODS

std::string ShrubberyCreationForm::drawingSchrubberies( void ) const
{
	std::string schrubberies =
	"               ,@@@@@@@,\n" \
	"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n" \
	"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n" \
	"  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" \
	"  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n" \
	"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n" \
	"   `&%\\ ` /%&'    |.|        \\ '|8'\n" \
	"       |o|        | |         | |\n" \
	"       |.|        | |         | |\n" \
	"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	
	return (schrubberies);
}

void	ShrubberyCreationForm::execute( Bureaucrat const &executor ) const
{
	AForm::execute(executor); // Calling pure virtual function
	// Now overrinding
	// Protecting failure exception ?
	std::ofstream	file(getTarget() + "_shrubbery"); // Stream class to write on files
	file << drawingSchrubberies();
	file.close();
	std::cout << T_GY "\nPlease have a look on < " T_GN << getTarget() <<"_shrubbery" << T_GY "> file... >\n" T_N;
	return ;
}