/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:35:48 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/13 01:57:45 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

// COPLIEN FORM

Bureaucrat::Bureaucrat( void )
{
	// Cannot be intantiated
    return ;
}

Bureaucrat::Bureaucrat( std::string const &name, int grade ) : _name(name)
{
	std::cout << T_GYHID "Bureaucrat Name and Grade constructor called" T_N << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) : _name(src._name)
{
	std::cout << T_GYHID "Bureaucrat Copy constructor called" T_N << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &rhs )
{
	std::cout << T_GYHID "Bureaucrat Assignation operator overload called" T_N << std::endl;
	// Remember that my name may be const
	this->_grade = rhs.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << T_GYHID "Bureaucrat destructor called" T_N << std::endl;
	return ;
}


// GETTERS

std::string const Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int               Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

// METHODS

void              Bureaucrat::decGrade( void )  //(++)
{
	this->_grade += 1;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

void              Bureaucrat::incGrade( void ) //(--)
{
	this->_grade -= 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return ;
}

void				Bureaucrat::signForm( Form &form ) const
{
	try
	{
		form.beSigned(*this);
		std::cout << T_GY "< " << T_BB << getName() << T_GY " > signs < ";
		std::cout << T_BB << form.getName() << T_GYB " >" << T_N << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Form::AlreadySignedException &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return ;
}

std::ostream &operator<<( std::ostream &o, const Bureaucrat &rhs )
{
	o << T_GY "Under the high authority of the Bureaucracy, < ";
	o << T_BB << rhs.getName() << T_GY " >, bureaucrat grade < ";
	o << T_BB << rhs.getGrade() << T_GYB " >" << T_N << std::endl;
	return (o);
}

// EXCEPTIONS

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (T_Y "Bureaucrat: The current grade is too low to be part of the bureaucrats." T_N);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (T_Y "Bureaucrat: The current grade is too high to be part of the bureaucrats.." T_N);
}