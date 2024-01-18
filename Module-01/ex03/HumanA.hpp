/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:12:38 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/29 18:21:08 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string  _name;
        Weapon&     _weapon;
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void    setName(std::string name);
        void    setWeapon(Weapon& weapon);
        void    attack(void);
};

#endif // HUMANA_HPP