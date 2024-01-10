/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:45:42 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/10 10:24:41 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main(void)
{
    try {
        Bureaucrat bureau("haben", 13);
        Form form("doc");

        bureau.signForm(form);
        std::cout << bureau << std::endl;
        std::cout << form << std::endl;

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


