/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 02:15:44 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/16 14:19:31 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
    
}
Intern::~Intern(void) {
    
}
Intern::Intern(const Intern& cpy){
    (void)cpy;
}
Intern& Intern::operator=(const Intern& rhs) {
    (void) rhs;
    return *this;
}
// makeform
AForm *    createPardonForm( std::string const target) {
    return (new PresidentialPardonForm(target));
}
AForm *   createRequestForm( std::string const target) {
    return (new RobotomyRequestForm(target));
}
AForm *   createShrubberyForm( std::string const target) {
    return (new ShrubberyCreationForm(target));
}

const char *	Intern::InvalidFormName::what(void) const throw()
{
	return ( "Error: Unknown Form Name." );	
}

AForm*  Intern::makeForm(std::string formName, std::string targetName) {
    typedef AForm* (*func)(std::string const); // defining the function signature of the forms to be created
    
    func forms[] = {&createPardonForm, &createRequestForm, &createShrubberyForm};
    std::string names[] = {"Pardon", "Request", "Shrubbery"};
    for (int i = 0; i < 3; i++) {
        if (!names[i].compare(formName)) {
            return forms[i](targetName);
        }
    }
    throw Intern::InvalidFormName();
}

// std::ostream& operator<<(std::ostream& os, const Intern& rhs) {
//     std::stringstream ss;
//     ss << rhs.;
//     os << ss.str();
//     return os;
// }