/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:54:57 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/14 22:00:17 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <sstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        ShrubberyCreationForm( void );											// Private Default constructor

    public:
        // Coplien  Form
        ShrubberyCreationForm( std::string const &target );						// Target constructor
		ShrubberyCreationForm( ShrubberyCreationForm const &src );				// Copy constructor
		ShrubberyCreationForm &operator=( ShrubberyCreationForm const &rhs );	// Assignation operator overload
        virtual ~ShrubberyCreationForm( void );									// Destructor

    // Methods
	void				execute( Bureaucrat const &executor ) const;			// Heriting from Mother class, now overriding
	std::string			drawingSchrubberies( void ) const;
};

#endif