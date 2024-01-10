/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:45:42 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/10 09:07:23 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main(void)
{
    try {
        Bureaucrat bureaucrat("haben", 12);

        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.whatCustom() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.whatCustom() << std::endl;
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


