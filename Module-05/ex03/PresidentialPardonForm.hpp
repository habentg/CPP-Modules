/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 01:40:13 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/12 01:42:26 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        PresidentialPardonForm();
    public:
        PresidentialPardonForm( const std::string target );
        PresidentialPardonForm( const PresidentialPardonForm& src );
        ~PresidentialPardonForm();
        PresidentialPardonForm&  operator=(const PresidentialPardonForm& rhs );
        // member function
        void        execute( const Bureaucrat& executor ) const;

};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& rhs);

#endif //!PRESIDENTIALPARDONFORM_HPP
