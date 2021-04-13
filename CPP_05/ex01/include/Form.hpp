/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 23:30:38 by salome            #+#    #+#             */
/*   Updated: 2021/04/13 01:29:19 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# define YES 1
# define NO 0

class Form;

#include "Bureaucrat.hpp"

class Form
{
    private:
        std::string const 	_name;
        int const  			_gradeToBeSigned;
		int const  			_gradeToBeExecuted;
		bool				_signedStatus;
        Form( void );																	// Private Default constructor

    public:
        // Coplien  Form
        Form( std::string const &name, int gradeToBeSigned, int gradeToBeExecuted );	// Name and Grade constructor
		Form( Form const &src );														// Copy constructor
		Form &operator=( Form const &rhs );												// Assignation operator overload
        ~Form( void );																	// Destructor
		
		// Nested class for exception handling (must not be coplien)
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	AlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

    // Getters
    std::string const getName( void ) const;
    int               getGradeToBeSigned( void ) const;
	int               getGradeToBeExecuted( void ) const;
	int               getSignedStatus( void ) const;

    // Methods
	void			beSigned( Bureaucrat const &bureaucrat );
};

class Form;

// Form output stream overload
std::ostream &operator<<( std::ostream &o, const Form &rhs );

#endif