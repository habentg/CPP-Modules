/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:27:19 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 02:20:52 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    return ;
}

Weapon::~Weapon (void)
{
    return ;
}
void Weapon::setType(std::string type)
{
    this->_type = type;
}

const std::string& Weapon::getType(void) const
{
    return this->_type;
}