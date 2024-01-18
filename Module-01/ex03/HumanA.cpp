/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:50:16 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 05:20:02 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
    return ;
}

HumanA::~HumanA(void)
{
    return ;
}
void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void HumanA::setName(std::string name)
{
    this->_name = name;
}

void    HumanA::setWeapon(Weapon& weapon)
{
    this->_weapon = weapon;
}