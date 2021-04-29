/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 23:50:31 by salome            #+#    #+#             */
/*   Updated: 2021/04/13 13:54:34 by sad-aude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

// COPLIEN FORM

Form::Form( std::string const &name, int gradeToBeSigned, int gradeToBeExecuted ) : 
	_name(name), _gradeToBeSigned(gradeToBeSigned), _gradeToBeExecuted(gradeToBeExecuted)
{
	std::cout << T_GYHID "Form Name and Grades constructor called" T_N << std::endl;
	if (_gradeToBeSigned < 1 || _gradeToBeExecuted < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToBeSigned > 150 || _gradeToBeExecuted > 150)
		throw Form::GradeTooLowException();
	this->_signedStatus = NO;
	return ;
}

Form::Form( Form const &src ) : 
	_name(src._name), _gradeToBeSigned(src.getGradeToBeSigned()), _gradeToBeExecuted(src.getGradeToBeExecuted())
{
	std::cout << T_GYHID "Form Copy constructor called" T_N << std::endl;
	*this = src;
}

Form &Form::operator=( Form const &rhs )
{
	std::cout << T_GYHID "Form Assignation operator overload called" T_N << std::endl;
	// Remember that my name and grades may be const
	this->_signedStatus = rhs.getSignedStatus();
	return (*this);
}

Form::~Form( void )
{
	std::cout << T_GYHID "Form destructor called" T_N << std::endl;
	return ;
}


// GETTERS

std::string const Form::getName( void ) const
{
	return (this->_name);
}

int               Form::getGradeToBeSigned( void ) const
{
	return (this->_gradeToBeSigned);
}

int               Form::getGradeToBeExecuted( void ) const
{
	return (this->_gradeToBeExecuted);
}

int               Form::getSignedStatus( void ) const
{
	return (this->_signedStatus);
}

// METHODS

void			Form::beSigned( Bureaucrat const &bureaucrat )
{
	if (bureaucrat.getGrade() > this->getGradeToBeSigned())
		throw Form::GradeTooLowException();
	else if (getSignedStatus())
		throw Form::AlreadySignedException();
	this->_signedStatus = YES;
}

std::ostream &operator<<( std::ostream &o, const Form &rhs )
{
	o << T_GY "The prerequisite grades for the form are < " T_BB << rhs.getGradeToBeSigned() << T_GY " > to sign it and < ";
	o << T_BB << rhs.getGradeToBeExecuted() << T_GY " > to execute it." << std::endl;
	o << T_GY "The, < " << rhs.getName() << T_GY " > form is currently ";
	if (!rhs.getSignedStatus())
		o << T_BB "not signed yet." T_N << std::endl;
	else
		o << T_BB "signed." T_N << std::endl;
	
	return (o);
}

// EXCEPTIONS

const char* Form::GradeTooLowException::what() const throw()
{
	return (T_Y "Form: The current grade is too low to manage forms." T_N);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return (T_Y "Form: The current grade is too high to manage forms." T_N);
}

const char* Form::AlreadySignedException::what() const throw()
{
	return (T_Y "Form: The current form has already been signed." T_N);
}