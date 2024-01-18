/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:45:42 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/16 14:24:08 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
    try {    
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("Shrubbery", "bender");
        std::cout << *rrf << std::endl;
        delete rrf; // we allocated in 'makeForm()'
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
    catch (Intern::InvalidFormName &e)
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

