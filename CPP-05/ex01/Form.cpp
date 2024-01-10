/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 02:59:41 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/10 10:34:30 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const int Form::grade_required_sign = 10;
const int Form::grade_required_execute = 5;
// -------------------------------Orthodox Canonical Form---------------------------------
// default consturctor
Form::Form(void)
    : _name("defaultForm"), _isSigned(false), _grade_sign(grade_required_sign), _grade_exec(grade_required_execute)
{
    if (this->_grade_sign > 150 || this->_grade_exec > 150)
        throw Form::GradeTooLowException();
    if (this->_grade_sign < 1 || this->_grade_exec < 1)
        throw Form::GradeTooHighException();
    // std::cout << this->_name << " Form default constructor" << std::endl;
}
// parameterized constructor
Form::Form(std::string name)
    : _name(name), _isSigned(false), _grade_sign(grade_required_sign), _grade_exec(grade_required_execute)
{
    if (this->_grade_sign > 150 || this->_grade_exec > 150)
        throw Form::GradeTooLowException();
    if (this->_grade_sign < 1 || this->_grade_exec < 1)
        throw Form::GradeTooHighException();
    // std::cout << this->_name << " Form default constructor" << std::endl;
}
// copy constructor
Form::Form(const Form& cpy)
    : _name("defaultForm"), _grade_sign(grade_required_sign), _grade_exec(grade_required_execute)
 {
    // std::cout << this->_name << " Form copy constructor" << std::endl;
    *this = cpy;
}
// copy assignment operator
Form& Form::operator=(const Form& rhs) {
    // std::cout << this->_name << " Form copy Assignment Operator" << std::endl;
    if (this != &rhs)
    {
        this->_isSigned = rhs.getGradeSign();
    }
    return *this;
}
// destuctor
Form::~Form(void) {
    // std::cout << this->_name << " Form destructor" << std::endl;
}
// insertion (<<) overloader - basicly creating an outfile stream that cout recognizes to desplay.
std::ostream& operator<<(std::ostream& os, const Form& rhs) {
    std::string output =  rhs.getName() + " Form needs {" + std::to_string(rhs.getGradeSign()) + "} grade to be signed and it needs {" + std::to_string(rhs.getGradeExcec()) + "} grade to be executed. But is it Signed: " + std::to_string(rhs.getIsSigned());
    os << output;
    return os;
}
// --------------------------------member functions----------------------------
// return a constant string name
std::string const   Form::getName(void) const {
    return this->_name;
}
// returns an int
int     Form::getGradeSign(void) const {
    return this->_grade_sign;
}
int     Form::getGradeExcec(void) const {
    return this->_grade_exec;
}
bool    Form::getIsSigned(void) const {
    return this->_isSigned;
}
void    Form::beSigned(Bureaucrat& bureau) {
    if (bureau.getGrade() <= this->getGradeSign())
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}
// incrementing the grade of the  Form 1 is the hights and 150 is the lowest
const char* Form::GradeTooHighException::whatCustom(void) const throw() {
    return "Form's Grade is too High!";
}
const char* Form::GradeTooLowException::whatCustom(void) const throw(){
    return "Form's Grade is too Low!";
}