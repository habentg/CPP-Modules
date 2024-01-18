/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 01:40:15 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/12 02:06:01 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// -------------------------------Orthodox Canonical Form---------------------------------
// default consturctor
// PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Robotomy-Request-Form", 72, 45)
// {
//     if (this->getGradeSign() > 150 || this->getGradeExcec() > 150)
//         throw AForm::GradeTooLowException();
//     if (this->getGradeSign() < 1 || this->getGradeExcec() < 1)
//         throw AForm::GradeTooHighException();
//     // std::cout << this->_name << " PresidentialPardonForm default constructor" << std::endl;
// }
// parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5)
{
    if (this->getGradeSign() > 150 || this->getGradeExcec() > 150)
        throw AForm::GradeTooLowException();
    if (this->getGradeSign() < 1 || this->getGradeExcec() < 1)
        throw AForm::GradeTooHighException();
    // std::cout << this->_name << " PresidentialPardonForm default constructor" << std::endl;
}
// copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy)
    : AForm(cpy.getName(), cpy.getGradeSign(), cpy.getGradeExcec())
 {
    // std::cout << this->_name << " PresidentialPardonForm copy constructor" << std::endl;
    // *this = cpy;
}
// copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    std::cout << this->getName() << " PresidentialPardonForm copy Assignment Operator" << std::endl;
    if (this != &rhs)
    {
        this->setSigned(rhs.getGradeSign());
    }
    return *this;
}
// destuctor
PresidentialPardonForm::~PresidentialPardonForm(void) {
    // std::cout << this->_name << " PresidentialPardonForm destructor" << std::endl;
}
// insertion (<<) overloader - basicly creating an outfile stream that cout recognizes to desplay.
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& rhs) {
    std::stringstream ss;
    ss << rhs.getName() << " needs {" << rhs.getGradeSign() << "} grade to be signed and it needs {" << rhs.getGradeExcec() << "} grade to be executed. But is it Signed: " << rhs.getIsSigned();
    os << ss.str();
    return os;
}

void PresidentialPardonForm::execute( const Bureaucrat& executor ) const {
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeExcec())
        throw AForm::GradeTooLowException();
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}