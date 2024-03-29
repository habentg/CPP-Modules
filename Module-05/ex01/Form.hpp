/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:11:43 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/16 13:39:21 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _grade_sign;
        int const           _grade_exec;
        Form(void);
    public:
        Form(std::string name);
        ~Form(void);
        Form(const Form& cpy);
        Form& operator=(const Form& rhs);
        // getters member functions
        std::string const   getName(void) const;
        bool                getIsSigned(void) const;
        int                 getGradeSign(void) const;
        int                 getGradeExcec(void) const;
        // feature
        void                beSigned(Bureaucrat& bureau);
        // custom exception class
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        // 
        static const int grade_required_sign;
        static const int grade_required_execute;
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif //!FORM_HPP