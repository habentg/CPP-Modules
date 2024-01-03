/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:02:45 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/03 18:35:24 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap scav("scav1");
    ScavTrap scav2(scav);
    ScavTrap scav3;

    scav3 = scav2;
    scav3.setName("scav3");
    scav2.setName("scav2");
    scav.attack(scav2.getName());
    scav2.takeDamage(5);
    scav2.takeDamage(5);
    scav2.takeDamage(5);
    scav2.beRepaired(5);
    scav2.attack(scav3.getName());
    return 0;
}