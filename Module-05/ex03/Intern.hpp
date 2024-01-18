/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 02:15:42 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/16 13:33:15 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& cpy);
        Intern& operator=(const Intern& rhs);
        ~Intern();
        // member function
        AForm*  makeForm(std::string formName, std::string targerName);
        
        class InvalidFormName : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif //!INTERN_HPP
