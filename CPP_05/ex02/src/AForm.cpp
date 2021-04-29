/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 23:50:31 by salome            #+#    #+#             */
/*   Updated: 2021/04/14 17:41:06 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

// COPLIEN FORM

AForm::AForm( std::string const &name, int gradeToBeSigned, int gradeToBeExecuted ) : 
	_name(name),
	_gradeToBeSigned(gradeToBeSigned),
	_gradeToBeExecuted(gradeToBeExecuted),
	_target("Null")
{
	std::cout << T_GYHID "AForm Name and Grades constructor called" T_N << std::endl;
	
	if (_gradeToBeSigned < 1 || _gradeToBeExecuted < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToBeSigned > 150 || _gradeToBeExecuted > 150)
		throw AForm::GradeTooLowException();
	
	this->_signedStatus = NO;
	return ;
}

AForm::AForm( AForm const &src ) : 
	_name(src._name), // Is const
	_gradeToBeSigned(src.getGradeToBeSigned()),
	_gradeToBeExecuted(src.getGradeToBeExecuted()), 
	_target(src.getTarget())
{
	std::cout << T_GYHID "AForm Copy constructor called" T_N << std::endl;
	*this = src;
}

AForm &AForm::operator=( AForm const &rhs )
{
	std::cout << T_GYHID "AForm Assignation operator overload called" T_N << std::endl;
	// Remember that my name and grades may be const
	this->_signedStatus = rhs.getSignedStatus();
	return (*this);
}

AForm::~AForm( void )
{
	std::cout << T_GYHID "AForm destructor called" T_N << std::endl;
	return ;
}


// GETTERS

std::string const AForm::getName( void ) const
{
	return (this->_name);
}

int               AForm::getGradeToBeSigned( void ) const
{
	return (this->_gradeToBeSigned);
}

int               AForm::getGradeToBeExecuted( void ) const
{
	return (this->_gradeToBeExecuted);
}

int               AForm::getSignedStatus( void ) const
{
	return (this->_signedStatus);
}

std::string const AForm::getTarget( void ) const
{
	return (this->_target);
}


// SETTERS

void				AForm::setTarget( std::string target )
{
	this->_target = target;
}


// METHODS

void			AForm::beSigned( Bureaucrat const &bureaucrat )
{
	if (bureaucrat.getGrade() > this->getGradeToBeSigned())
		throw AForm::GradeTooLowException();
	else if (getSignedStatus())
		throw AForm::AlreadySignedException();
	this->_signedStatus = YES;
}

/* A pure virtual function (or abstract function) in C++ is a virtual function
** for which we can have implementation, But we must override that function in
** the derived class, otherwise the derived class will also become abstract class */

void			AForm::execute( Bureaucrat const &executor ) const
{
	if (executor.getGrade() > this->getGradeToBeExecuted())
		throw AForm::GradeTooLowException();
	else if (!getSignedStatus())
		throw AForm::NotSignedYetException();
}

std::ostream &operator<<( std::ostream &o, const AForm &rhs )
{
	o << T_GY "The prerequisite grades for the form are < " T_BB << rhs.getGradeToBeSigned() << T_GY " > to sign it and < ";
	o << T_BB << rhs.getGradeToBeExecuted() << T_GY " > to execute it." << std::endl;
	o << T_GY "The, < " T_BB << rhs.getName() << T_GY " > form is currently ";
	if (!rhs.getSignedStatus())
		o << T_BB "not signed yet." T_N << std::endl;
	else
		o << T_BB "signed." T_N << std::endl;
	
	return (o);
}


// EXCEPTIONS

const char* AForm::GradeTooLowException::what() const throw()
{
	return (T_Y "Form: The current grade is too low to manage forms." T_N);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return (T_Y "Form: The current grade is too high to manage forms." T_N);
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return (T_Y "Form: The current form has already been signed." T_N);
}

const char* AForm::NotSignedYetException::what() const throw()
{
	return (T_Y "Form: The current form has to be signed to allow execution." T_N);
}