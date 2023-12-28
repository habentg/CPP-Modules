/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:14:13 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 05:02:59 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    private:
        std::string  _name;
        Weapon* _weapon;
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void    setWeapon(Weapon& weapon);
        void    attack(void);
};

#endif// HUMANB_HPP