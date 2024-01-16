/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:54:14 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/12 04:31:02 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// -------------------------------Orthodox Canonical ShrubberyCreationForm---------------------------------
// default consturctor
// ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyForm", 145, 137)
// {
//     if (this->getGradeSign() > 150 || this->getGradeExcec() > 150)
//         throw AForm::GradeTooLowException();
//     if (this->getGradeSign() < 1 || this->getGradeExcec() < 1)
//         throw AForm::GradeTooHighException();
//     // std::cout << this->_name << " ShrubberyCreationForm default constructor" << std::endl;
// }
// parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137)
{
    if (this->getGradeSign() > 150 || this->getGradeExcec() > 150)
        throw AForm::GradeTooLowException();
    if (this->getGradeSign() < 1 || this->getGradeExcec() < 1)
        throw AForm::GradeTooHighException();
    // std::cout << this->_name << " ShrubberyCreationForm default constructor" << std::endl;
}
// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy)
    : AForm(cpy.getName(), cpy.getGradeSign(), cpy.getGradeExcec())
 {
    // std::cout << this->_name << " ShrubberyCreationForm copy constructor" << std::endl;
    // *this = cpy;
}
// copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    std::cout << this->getName() << " ShrubberyCreationForm copy Assignment Operator" << std::endl;
    if (this != &rhs)
    {
        this->setSigned(rhs.getGradeSign());
    }
    return *this;
}
// destuctor
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    // std::cout << this->_name << " ShrubberyCreationForm destructor" << std::endl;
}
// insertion (<<) overloader - basicly creating an outfile stream that cout recognizes to desplay.
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& rhs) {
    std::stringstream ss;
    ss << rhs.getName() << " AForm needs {" << rhs.getGradeSign() << "} grade to be signed and it needs {" << rhs.getGradeExcec() << "} grade to be executed. But is it Signed: " << rhs.getIsSigned();
    os << ss.str();
    return os;
}

std::string const tree_0 = "\n"
"              ,@@@@@@@,                  \n"      
"      ,,,.   ,@@@@@@/@@,  .oo8888o.      \n"      
"   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o     \n"       
"  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'    \n"        
"  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'    \n"        
"  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'     \n"       
"  `&%\\ ` /%&'    |.|        \\ '|8'       \n"     
"      |o|        | |         | |         \n"   
"      |.|        | |         | |         \n"   
"    \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_ \n";
       
std::string const tree_1 = "\n"
"          _..._ ._                      \n"   
"       ;-._   .'   `\\                   \n"  
"     .'    `\\/       ;                  \n"  
"     |       `\\.---._|                  \n"  
"  .--;   . ( .'      '.                 \n"   
" / _  \\_  './ _.       `-._             \n"       
"( = \\  )`""'\\;--.         /             \n"       
"{= (|  )     /`.         /     .'|      \n"                
"( =_/  )__..-\\         .'     / /       \n"             
" \\    }/    / ;.____.-;/\\   .` /        \n"            
"  '--' |  .'   |       \\ \\  |  ;        \n"            
"       \\  '    /       |. ;  \\/         \n"           
"        )    .'`-.    / ; |  /\\         \n"           
"       /__.-'   , \\_.'  | | ;  ;        \n"            
"                |\\      |`| |  |        \n"            
"                 \\`\\    | | |  |        \n"            
"                  \\ `\\  | | ;  ;        \n"            
"                   |  ; | | /  /        \n"            
"                   |  | | |/  /         \n"           
"                   ;  | | /  /          \n"          
"                    \\  \\;/  /           \n"         
"                     \\  \\  /            \n"        
"                      \\  Y/             \n"       
"                       |  |             \n"       
"                       |  |             \n"
"                       |  |             \n"
"                       |  |             \n"
"                       \\  |             \n"
"                        \\_/             \n";

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeExcec())
        throw AForm::GradeTooLowException();
    std::string filename = this->getName() + "_shrubbery";
    std::ofstream shruFile(filename.c_str());
    shruFile << tree_0;
}
