/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:55:03 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/12 04:31:23 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {
    private:
        ShrubberyCreationForm(void);
    public:
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
        // member function

        void    execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& rhs);

#endif //!SHRUBBERYCREATIONFORM_HPP