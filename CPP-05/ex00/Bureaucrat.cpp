/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 02:59:41 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/10 10:34:30 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// -------------------------------Orthodox Canonical Form---------------------------------
// default consturctor
Bureaucrat::Bureaucrat(void) : _name("default"), _grade(1) {
    // std::cout << this->_name << " Bureaucrat default constructor" << std::endl;
}
// parameterized constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    // if (grade > 150)
    //     throw 4.5;
    // if (grade < 1)
    //     throw "Exception: grade too High!";
    this->_grade = grade; 
    // std::cout << this->_name << " Bureaucrat default constructor" << std::endl;
}
// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& cpy) {
    // std::cout << this->_name << " Bureaucrat copy constructor" << std::endl;
    *this = cpy;
}
// copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    // std::cout << this->_name << " Bureaucrat copy Assignment Operator" << std::endl;
    if (this != &rhs)
    {
        // this->_name = rhs.getName();
        this->_grade = rhs.getGrade();
    }
    return *this;
}
// destuctor
Bureaucrat::~Bureaucrat(void) {
    // std::cout << this->_name << " Bureaucrat destructor" << std::endl;
}
// insertion (<<) overloader - basicly creating an outfile stream that cout recognizes to desplay.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
    std::string output =  rhs.getName() + ", grade is " + std::to_string(rhs.getGrade());
    os << output;
    return os;
}
// --------------------------------member functions----------------------------
// return a constant string name
std::string const   Bureaucrat::getName(void) const {
    return this->_name;
}
// returns an int
int Bureaucrat::getGrade(void) const {
    return this->_grade;
}
// incrementing the grade of the  Bureaucrat 1 is the hights and 150 is the lowest
void    Bureaucrat::incrementGrade(void) {
    if ((this->_grade - 1) < 1)
        throw GradeTooHighException();
   this->_grade--;
}
// decrementing the grade of the  Bureaucrat 1 is the hights and 150 is the lowest
void    Bureaucrat::decrementGrade(void) {
    if ((this->_grade + 1) > 150)
        throw GradeTooLowException();
    this->_grade++;

}

const char* Bureaucrat::GradeTooHighException::whatCustom(void) const throw() {
    return "Bureaucrat's Grade is too High!";
}
const char* Bureaucrat::GradeTooLowException::whatCustom(void) const throw(){
    return "Bureaucrat's Grade is too Low!";
}