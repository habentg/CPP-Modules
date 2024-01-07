/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:10:55 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 19:20:06 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// default constructor
Cure::Cure(void) : AMateria("cure") {
    // std::cout << "# Cure Constructor Called #" << std::endl;
}
// copy constructor
Cure::Cure(const Cure& cpy) : AMateria("cure"){
    // std::cout << "# Cure Copy Constructor Called #" << std::endl;
    *this = cpy;
}
// copy assignment operator
Cure& Cure::operator=(const Cure& rhs) {
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}
// destructor
Cure::~Cure(void) {
    // std::cout << "# Cure Destructor Called #" << std::endl;
}
// --------------------member func -----------------------------
// clone() -- pure virtual function from 'AMateria'; 
// it clones the current object and returns address of the clone
AMateria* Cure::clone(void) const {
    return (new Cure(*this));
}
// use() -- accepts reference to the interface 'Icharacter'
// 
void    Cure::use( ICharacter& target )
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}