/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:10:55 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 00:59:52 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// default constructor
Ice::Ice(void) : AMateria("ice") {
    std::cout << "# Ice Constructor Called #" << std::endl;
}
// copy constructor
Ice::Ice(const Ice& cpy) : AMateria("ice"){
    std::cout << "# Ice Copy Constructor Called #" << std::endl;
    *this = cpy;
}
// copy assignment operator
Ice& Ice::operator=(const Ice& rhs) {
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}
// destructor
Ice::~Ice(void) {
    std::cout << "# Ice Destructor Called #" << std::endl;
}
// --------------------member func -----------------------------
// clone() -- pure virtual function from 'AMateria'; 
// it clones the current object and returns address of the clone
AMateria* Ice::clone(void) const {
    return (new Ice(*this));
}
// use() -- accepts reference to the interface 'Icharacter'
// 
void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}