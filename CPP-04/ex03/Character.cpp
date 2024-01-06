/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:20:07 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 00:55:45 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// default constructor
    // -> character object has to be constructed with a name

// parameterized constructor
Character::Character(std::string const & name) {
    for (size_t i = 0; i < 4; i++)
    {
        this->_inventory[i] = NULL;
    }
    std::cout << "# " << this->_name << ": Character Constructor Called #" << std::endl;
}
// destructor - we allocating the inventory so yeah
Character::~Character(void) {
    for (size_t i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
        {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
    std::cout << "# " << this->_name << ": Character Destructor Called #" << std::endl;
}
// copy constructor
Character::Character(const Character& cpy) {
    std::cout << "# Character Copy Constructor Called #" << std::endl;
    *this = cpy;
}
// copy assignment operator
// wipe clean before deep copy
Character& Character::operator=(const Character& rhs) {
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        for (size_t i = 0; i < 4; i++)
        {
            if (this->_inventory[i])
            {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
        }
        for (size_t i = 0; i < 4; i++)
            this->_inventory[i] = rhs._inventory[i];
    }
    return *this;
}
// member functions from ICharacter
// gets the name
std::string const & Character::getName() const {
    return this->_name;
}
// recieves 'AMateria' and tries to put it in the inventory (into one of the 4 slots).
// if invontory is full, just say something
void Character::equip(AMateria* m) {
    if (!m)
    {
        std::cout << "# INVALID/EMPTY Materrial: can't equip that #" << std::endl;
        return ;
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            std::cout << "# " << this->_name << ": equiped at index " << i << " #" << std::endl;
            return ;
        }
    }
    std::cout << "# " << this->_name << ": cant be equiped! #" << std::endl;
}
// self explanatory really
void    Character::unequip(int idx) {
     if (idx > 3 || idx < 0)
    {
        std::cout << "# INVALID IDX: can't unequip any Material #" << std::endl;
        return ;
    }
    if (this->_inventory[idx])
    {
        // delete this->_inventory[idx]; // The unequip() member function must NOT delete the Materia! NO IDEA HOW THE FUCK then
        // just de-attach the pointer to that specific equipment (it will be cleaned during destruction of character)
        this->_inventory[idx] = NULL;
        std::cout << "# " << this->_name << " succesfully unequipped #" << std::endl;
    }
    else
        std::cout << "# " << this->_name << " failed to be unequiped #" << std::endl;
}
// if a material is available at idx, we want it  to be used by 'target',
void    Character::use(int idx, ICharacter& target) {
    if (idx > 3 || idx < 0)
    {
        std::cout << "# INVALID IDX: can't use any Material #" << std::endl;
        return ;
    }
    if (this->_inventory[idx])
    {
        this->_inventory[idx]->use(target);
        std::cout << "# " << this->_name << " is using " << this->_inventory[idx]->getType() << " #" << std::endl;
    }
    else
        std::cout << "# " << this->_name << " can't use any Material #" << std::endl;
}