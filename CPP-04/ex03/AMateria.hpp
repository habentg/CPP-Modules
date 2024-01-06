/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:11:07 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/06 23:27:44 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMateria_HPP
# define AMateria_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;
/* three member functions
    -> getType() -- to return the 'type' of the object.
    -> clone() -- pure virtual function, i.e, no implementation in this class but every
        object created using this class has to implement it (a must!),
    -> use() -- virual function, i.e, it will have a default implementation here but it 
    will be determined on run-time on which 'use' function to run. 
*/
class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(const AMateria& cpy);
        AMateria&   operator=(const AMateria& rhs);
        ~AMateria(void);

        // member func
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone(void) const = 0; // pure virtual function 
        virtual void use(ICharacter& target); // used really
};

#endif// !AMateria_HPP
