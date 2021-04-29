/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:35:51 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/14 18:19:10 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define CLEAN "\e[1;1H\e[2J"
# define T_N "\033[00m"
# define T_WH "\033[1;37m"
# define T_I "\033[3m"
# define T_BO "\033[01"
# define T_Y "\033[00;33m"
# define T_GN "\033[00;32m"
# define T_CY "\033[00;36m"
# define T_PU "\033[00;35m"
# define T_R "\033[00;31m"
# define T_GY "\033[03;90m"
# define T_GYHID "\033[2;34m"
# define T_GYB "\033[01;90m"
# define T_B "\033[00;34m"
# define T_BB "\033[01;34m"
# define T_BHID "\033[2;34m"

#include <iostream>
#include <stdexcept>

class Bureaucrat;

#include "AForm.hpp"

class Bureaucrat
{
    private:
        std::string const	_name;
        int					_grade;
        Bureaucrat( void );										// Private Default constructor

    public:
        // Coplien  Form
        Bureaucrat( std::string const &name, int grade );		// Name and Grade constructor
		Bureaucrat( Bureaucrat const &src );					// Copy constructor
		Bureaucrat &operator=( Bureaucrat const &rhs );			// Assignation operator overload
        ~Bureaucrat( void );									// Destructor
		
		// Nested class for exception handling (must not be coplien)
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();		// Returns a string that describe what error occured
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

    // Getters
    std::string const getName( void ) const;
    int               getGrade( void ) const;

    // Methods
    void              	decGrade( void ); //(++)
    void               	incGrade( void ); //(--)
	void				signForm( AForm &form ) const;
	void				executeForm( AForm const &form ) const;
};

// Bureaucrat output stream overload
std::ostream &operator<<( std::ostream &o, const Bureaucrat &rhs );

#endif