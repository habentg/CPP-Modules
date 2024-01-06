/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:16:54 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 00:40:00 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class ICharacter;
class AMateria;

class   Character : public ICharacter {
    protected:
        std::string _name;
        AMateria*   _inventory[4]; 
    public:
        Character(void);
        Character(std::string const & type);
        Character(const Character& cpy);
        Character&   operator=(const Character& rhs);
        ~Character(void);
        // member func from ICharacter
        std::string const & getName() const;
        void        equip(AMateria* m);
        void        unequip(int idx);
        void        use(int idx, ICharacter& target);
};
#endif //!CHARACTER_HPP
