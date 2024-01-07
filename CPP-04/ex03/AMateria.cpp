/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:02:18 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 19:19:59 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
// ----------------- constructors ------------------
AMateria::AMateria(void) : type("") {
    // std::cout << "# AMateria Constructor Called #" << std::endl;
}
// ----------------- Parameterized constructors ------------------
AMateria::AMateria(std::string const & type) : type(type) {
    // std::cout << "# " << this->type << "'s AMateria Constructor Called #" << std::endl;
}
// ----------------- destructor ------------------
AMateria::~AMateria(void) {
    // std::cout << "# AMateria Destructor Called #" << std::endl;
}
// ----------------- Copy constructor ------------------
AMateria::AMateria(const AMateria& cpy) {
    // std::cout << "# AMateria Copy Constructor Called #" << std::endl;
    *this = cpy;
}
// ----------------- Assignment operator ------------------
// copying a AMateria does not make sense ---- from the subject
// AMateria& AMateria::operator=(const AMateria& rhs) {
//     if (this != &rhs)
//         this->type = rhs.type;
//     return *this;
// }

// ----------------- member functions ------------------
std::string const & AMateria::getType() const {
    return this->type;
}
// used would make more sense
void AMateria::use(ICharacter& target) {
    std::cout << "* " << this->type << " used on" << target.getName() << " *" << std::endl;
}