/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:22:52 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 19:07:10 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;   // forward declaration - to avoid circular dependency
                    // just tells the compler that ICharacter is a class and it exists don't worry about it
class AMateria {
    protected:
        std::string type;
    public:
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(AMateria const & src);
        virtual ~AMateria();
        std::string const & getType() const;
        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);
};

#endif // !AMATERIA_HPP

/*
    AMateria is an abstract class with
        * one protected member variable 'type'
        * three member functions
            -> getType() -- to return the 'type' of the object.
            -> clone() -- pure virtual function, i.e, no implementation in this class but every
                object created using this class has to implement it (a must!),
            -> use() -- virual function, i.e, it will have a default implementation here but it 
            will be determined on run-time on which 'use' function to run. 
*/

