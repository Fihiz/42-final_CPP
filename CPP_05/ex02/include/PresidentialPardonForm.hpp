/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:26:46 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/14 18:19:06 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        PresidentialPardonForm( void );											// Private Default constructor

    public:
        // Coplien  Form
        PresidentialPardonForm( std::string const &target );					// Target constructor
		PresidentialPardonForm( PresidentialPardonForm const &src );			// Copy constructor
		PresidentialPardonForm &operator=( PresidentialPardonForm const &rhs );	// Assignation operator overload
        virtual ~PresidentialPardonForm( void );								// Destructor

    // Methods
	void		execute( Bureaucrat const &executor ) const;					// Heriting from Mother class, now overriding
};

#endif