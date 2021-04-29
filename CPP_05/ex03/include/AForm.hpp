/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 23:30:38 by salome            #+#    #+#             */
/*   Updated: 2021/04/14 21:58:33 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# define YES 1
# define NO 0

class AForm;

#include "Bureaucrat.hpp"

/* Form is now becoming an Abstract class to make concrete derived objects.
** That is why Form becomes AForm.
** Remember, in our previous form.hpp/cpp, we had a getGradeToBeExecuted but
** we didn't use it. In our concrete derived objects, we'll use it by making
** doing thing to our derived forms. */

class AForm
{
    private:
        std::string const 	_name;
        int const  			_gradeToBeSigned;
		int const  			_gradeToBeExecuted;
		bool				_signedStatus;
		std::string			_target;														// Now taking a target to execute things on it
        AForm( void );																		// Private Default constructor

    public:
        // Coplien Form
        AForm( std::string const &name, int gradeToBeSigned, int gradeToBeExecuted );		// Name and Grade constructor
		AForm( AForm const &src );															// Copy constructor
		AForm &operator=( AForm const &rhs );												// Assignation operator overload
        virtual ~AForm( void );																// Destructor
		
		// Nested classes for exception handling (must not be coplien)
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
		class	NotSignedYetException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

    // Getters
    std::string const 	getName( void ) const;
    int               	getGradeToBeSigned( void ) const;
	int               	getGradeToBeExecuted( void ) const;
	int              	getSignedStatus( void ) const;
	std::string	const	getTarget( void ) const;

	// Setters
	void				setTarget( std::string target );

    // Methods
	void				beSigned( Bureaucrat const &bureaucrat );
	virtual void		execute( Bureaucrat const &executor ) const = 0;					// Pure virtual function that make doing things in derived
};

//class AForm;

// AForm output stream overload
std::ostream &operator<<( std::ostream &o, const AForm &rhs );

#endif