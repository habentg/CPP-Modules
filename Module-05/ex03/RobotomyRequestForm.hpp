/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:05:59 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/11 23:48:03 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        RobotomyRequestForm();
    public:
        RobotomyRequestForm( const std::string target );
        RobotomyRequestForm( const RobotomyRequestForm& src );
        ~RobotomyRequestForm();
        RobotomyRequestForm&  operator=(const RobotomyRequestForm& rhs );
        // member function
        void        execute( const Bureaucrat& executor ) const;

};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& rhs);

#endif //!ROBOTOMYREQUESTFORM_HPP
