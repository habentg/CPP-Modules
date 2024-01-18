/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 02:59:57 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/16 13:33:15 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include "AForm.hpp"
#include <sstream>

class AForm;

class Bureaucrat {
    private:
        std::string const   _name;
        int                 _grade;
        Bureaucrat(void);
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& cpy);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        ~Bureaucrat(void);
        std::string const   getName() const;
        int                 getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
        void    signForm(AForm& form);
        void    executeForm(AForm const & form);
        // publicly inheriting exception so we can have access to the functionalities of exception in c++;
        // declaring a 'what' member function (knock-off of the original 'what' function in exception class)
        // the 'throw()' is basicly an indicator that this function doesnt throw an exception. GUARANTEED!!
            // in its implementation it just returns a C-style string. there is no way to fail for that 💀💀💀💀💀💀
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif // !BUREAUCRAT_HPP