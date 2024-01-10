/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 02:59:41 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/10 10:34:30 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const int AForm::grade_required_sign = 10;
const int AForm::grade_required_execute = 5;
// -------------------------------Orthodox Canonical AForm---------------------------------
// default consturctor
AForm::AForm(void)
    : _name("defaultAForm"), _isSigned(false), _grade_sign(grade_required_sign), _grade_exec(grade_required_execute)
{
    if (this->_grade_sign > 150 || this->_grade_exec > 150)
        throw AForm::GradeTooLowException();
    if (this->_grade_sign < 1 || this->_grade_exec < 1)
        throw AForm::GradeTooHighException();
    // std::cout << this->_name << " AForm default constructor" << std::endl;
}
// parameterized constructor
AForm::AForm(std::string name)
    : _name(name), _isSigned(false), _grade_sign(grade_required_sign), _grade_exec(grade_required_execute)
{
    if (this->_grade_sign > 150 || this->_grade_exec > 150)
        throw AForm::GradeTooLowException();
    if (this->_grade_sign < 1 || this->_grade_exec < 1)
        throw AForm::GradeTooHighException();
    // std::cout << this->_name << " AForm default constructor" << std::endl;
}
// copy constructor
AForm::AForm(const AForm& cpy)
    : _name("defaultAForm"), _grade_sign(grade_required_sign), _grade_exec(grade_required_execute)
 {
    // std::cout << this->_name << " AForm copy constructor" << std::endl;
    *this = cpy;
}
// copy assignment operator
AForm& AForm::operator=(const AForm& rhs) {
    // std::cout << this->_name << " AForm copy Assignment Operator" << std::endl;
    if (this != &rhs)
    {
        this->_isSigned = rhs.getGradeSign();
    }
    return *this;
}
// destuctor
AForm::~AForm(void) {
    // std::cout << this->_name << " AForm destructor" << std::endl;
}
// insertion (<<) overloader - basicly creating an outfile stream that cout recognizes to desplay.
std::ostream& operator<<(std::ostream& os, const AForm& rhs) {
    std::string output =  rhs.getName() + " AForm needs {" + std::to_string(rhs.getGradeSign()) + "} grade to be signed and it needs {" + std::to_string(rhs.getGradeExcec()) + "} grade to be executed. But is it Signed: " + std::to_string(rhs.getIsSigned());
    os << output;
    return os;
}
// --------------------------------member functions----------------------------
// return a constant string name
std::string const   AForm::getName(void) const {
    return this->_name;
}
// returns an int
int     AForm::getGradeSign(void) const {
    return this->_grade_sign;
}
int     AForm::getGradeExcec(void) const {
    return this->_grade_exec;
}
bool    AForm::getIsSigned(void) const {
    return this->_isSigned;
}
void    AForm::beSigned(Bureaucrat& bureau) {
    if (bureau.getGrade() <= this->getGradeSign())
        this->_isSigned = true;
    else
        throw AForm::GradeTooLowException();
}
// incrementing the grade of the  AForm 1 is the hights and 150 is the lowest
const char* AForm::GradeTooHighException::whatCustom(void) const throw() {
    return "AForm's Grade is too High!";
}
const char* AForm::GradeTooLowException::whatCustom(void) const throw(){
    return "AForm's Grade is too Low!";
}