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
    public:
        AForm(void);
        AForm(std::string name);
        ~AForm(void);
        AForm(const AForm& cpy);
        AForm& operator=(const AForm& rhs);
        // member functions
        std::string const   getName(void) const;
        bool                getIsSigned(void) const;
        int                 getGradeSign(void) const;
        int                 getGradeExcec(void) const;
        void                beSigned(Bureaucrat& bureau);
        // custom exception class
        class GradeTooHighException : public std::exception {
            public:
                const char* whatCustom() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* whatCustom() const throw();
        };
        static const int grade_required_sign;
        static const int grade_required_execute;
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif //!AFORM_HPP