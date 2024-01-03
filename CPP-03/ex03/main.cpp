/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:02:45 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/03 18:38:20 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap frag("frag1");
    FragTrap frag2(frag);
    FragTrap frag3;

    frag3 = frag2;
    frag3.setName("frag3");
    frag2.setName("frag2");
    frag.attack(frag2.getName());
    frag2.takeDamage(5);
    frag2.takeDamage(5);
    frag2.takeDamage(5);
    frag2.beRepaired(5);
    frag2.attack(frag3.getName());
    return 0;
}