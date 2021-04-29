/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:27:07 by sad-aude          #+#    #+#             */
/*   Updated: 2021/04/14 18:20:47 by salome           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        RobotomyRequestForm( void );										// Private Default constructor

    public:
        // Coplien  Form
        RobotomyRequestForm( std::string const &target );					// Target constructor
		RobotomyRequestForm( RobotomyRequestForm const &src );				// Copy constructor
		RobotomyRequestForm &operator=( RobotomyRequestForm const &rhs );	// Assignation operator overload
        virtual ~RobotomyRequestForm( void );								// Destructor

    // Methods
	void		execute( Bureaucrat const &executor ) const;				// Heriting from Mother class, now overriding
};

#endif