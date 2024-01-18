/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:07:52 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/16 14:11:56 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// -------------------------------Orthodox Canonical Form---------------------------------
// default consturctor
// RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy-Request-Form", 72, 45)
// {
//     if (this->getGradeSign() > 150 || this->getGradeExcec() > 150)
//         throw AForm::GradeTooLowException();
//     if (this->getGradeSign() < 1 || this->getGradeExcec() < 1)
//         throw AForm::GradeTooHighException();
//     // std::cout << this->_name << " RobotomyRequestForm default constructor" << std::endl;
// }
// parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 72, 45)
{
    if (this->getGradeSign() > 150 || this->getGradeExcec() > 150)
        throw AForm::GradeTooLowException();
    if (this->getGradeSign() < 1 || this->getGradeExcec() < 1)
        throw AForm::GradeTooHighException();
    // std::cout << this->_name << " RobotomyRequestForm default constructor" << std::endl;
}
// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy)
    : AForm(cpy.getName(), cpy.getGradeSign(), cpy.getGradeExcec())
 {
    // std::cout << this->_name << " RobotomyRequestForm copy constructor" << std::endl;
    // *this = cpy;
}
// copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    std::cout << this->getName() << " RobotomyRequestForm copy Assignment Operator" << std::endl;
    if (this != &rhs)
    {
        this->setSigned(rhs.getGradeSign());
    }
    return *this;
}
// destuctor
RobotomyRequestForm::~RobotomyRequestForm(void) {
    // std::cout << this->_name << " RobotomyRequestForm destructor" << std::endl;
}

// member function
void        RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    static int i = 0;

    // std::cout << "the value of i: " << i << std::endl;
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeExcec())
        throw AForm::GradeTooLowException();
    std::cout << " * drilling noises * " << std::endl;
    if (i % 2 == 0)
        std::cout << this->getName() << " has been robotomized successfully!!" << std::endl;
    else
        std::cout << "robotomizing " << this->getName() << " has failed!!" << std::endl;
    i++;
}
// insertion (<<) overloader - basicly creating an outfile stream that cout recognizes to desplay.
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& rhs) {
    std::stringstream ss;
    ss << rhs.getName() << " needs {" << rhs.getGradeSign() << "} grade to be signed and it needs {" << rhs.getGradeExcec() << "} grade to be executed. But is it Signed: " << rhs.getIsSigned();
    os << ss.str();
    return os;
}