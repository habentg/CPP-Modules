/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:45:42 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/16 14:07:15 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try {
        Bureaucrat bureau("haben", 23);
        // ShrubberyCreationForm shrub("shrubbery");
        PresidentialPardonForm     rob("robot");

        // std::cout << shrub << std::endl;
        // bureau.signForm(shrub);
        // bureau.executeForm(shrub);        
        bureau.signForm(rob);
        // std::cout << "bureau's grade: " << bureau.getGrade() << std::endl;
        bureau.executeForm(rob);        
        bureau.executeForm(rob);        
        bureau.executeForm(rob);        
        bureau.executeForm(rob);        
        bureau.executeForm(rob);        
        bureau.executeForm(rob);        
        bureau.executeForm(rob);        
        bureau.executeForm(rob);        
        bureau.executeForm(rob);        
        bureau.executeForm(rob);        
        bureau.executeForm(rob);        
        bureau.executeForm(rob);        
        bureau.executeForm(rob);        
        std::cout << rob << std::endl;

    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (AForm::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (AForm::FormNotSignedException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (int code)
    {
        std::cout << code << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Exception: An Unknown Exception has been cought!!" << std::endl;
    }
}


