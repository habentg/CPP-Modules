/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:11:43 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/10 10:17:04 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _grade_sign;
        int const           _grade_exec;
        AForm(void);
    public:
        AForm(std::string name, int g_sign, int g_exec);
        virtual ~AForm(void);
        AForm(const AForm& cpy);
        AForm& operator=(const AForm& rhs);
        // member functions
        std::string const   getName(void) const;
        bool                getIsSigned(void) const;
        int                 getGradeSign(void) const;
        int                 getGradeExcec(void) const;
        void                beSigned(Bureaucrat& bureau);
        void                setSigned(bool tf);
        virtual void        execute( const Bureaucrat& executor ) const = 0;
        // custom exception class
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
        static const int grade_required_sign;
        static const int grade_required_execute;
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif //!AFORM_HPP