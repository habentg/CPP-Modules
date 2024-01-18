/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:27:03 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 19:09:59 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{

private:
    std::string _name;
    AMateria    *_inventory[4];

public:
    Character(std::string const &name);
    Character(Character const &src);
    ~Character();

    Character&          operator=(Character const &rhs);

    std::string const&  getName() const;
    void                equip(AMateria* m);
    void                unequip(int idx);
    void                use(int idx, ICharacter& target);
};

#endif // !CHARACTER_HPP

/*
    Character is a class with
        * one private member variable 'name'
        * one private member variable 'inventory' which is an array of AMateria pointers
        * three member functions
            -> getName() -- to return the 'name' of the object.
            -> equip() -- to equip a materia in the inventory.
            -> unequip() -- to unequip a materia from the inventory.
            -> use() -- to use a materia from the inventory.
*/