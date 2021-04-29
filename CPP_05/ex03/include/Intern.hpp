/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:09:53 by salome            #+#    #+#             */
/*   Updated: 2021/04/14 21:45:15 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
		// Our 3 form known names
		static std::string _formNames[3];
		// Our three possible pointers to create AForm derived objects
		AForm	*_makeShrubberyForm( std::string const target );
		AForm	*_makeRobotomyForm( std::string const target );
		AForm	*_makePresidentialPardonForm( std::string const target );



    public:
        // Coplien  Form
		Intern( void );											// Default constructor
		Intern( Intern const &src );							// Copy constructor
		Intern &operator=( Intern const &rhs );					// Assignation operator overload
        ~Intern( void );										// Destructor

    // Methods
	AForm	*makeForm( std::string const formName, std::string const formTarget );
	
};

#endif


/* There is an Intern class.
It has a makeForm function that works as specified by the subject.
The makeForm function should really use some kind of array of pointers 
to member functions to handle the creation of Forms. 
If it's using a worse method, like if/elseif/elseif/else branchings, or some other ugly stuff like this, please count this as Wrong. */
