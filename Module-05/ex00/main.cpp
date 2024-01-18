/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:45:42 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/16 13:33:15 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main(void)
{
    try {
        Bureaucrat bureaucrat("haben", 1);
        
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException &e) // custom
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) // custom
    {
        std::cout << e.what() << std::endl;
    }
    catch (int code) // used to catch an error thrown through an int
    {
        std::cout << "code number thrown: " << code << std::endl;
    }
    catch (const char *code) // used to catch an error thrown through an int
    {
        std::cout << "code number thrown: " << code << std::endl;
    }
    catch (const std::exception& e) // used to catch errors that are thrown using the std::___ exceptions
    {
        std::cout << e.what() << std::endl;
    }
    catch (...) // used to catch an exceptions thats not cought explicitly
    {
        std::cout << "Exception: An Unknown Exception has been cought!!" << std::endl;
    }
}


