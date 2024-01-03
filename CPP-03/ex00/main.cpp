/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:02:45 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/03 20:34:33 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap("Clap1");
    ClapTrap clap2(clap);
    ClapTrap clap3;

    clap3 = clap2;
    clap3.setName("Clap3");
    clap2.setName("Clap2");
    for (int i = 0; i < 15; i++)
        clap.attack(clap2.getName());
    clap2.takeDamage(14);
    clap2.beRepaired(10);
    clap2.beRepaired(10);
    clap2.attack(clap2.getName());
    std::cout << "------------#################--------" << std::endl;
    std::cout << "clap1 hitpoint: " << clap.getHitPoint() << std::endl;
    std::cout << "clap1 enrgy po: " << clap.getEnrgPoint() << std::endl;
    std::cout << "clap1 attDamag: " << clap.getAttDamagePoint() << std::endl;
    std::cout << "------------#################--------" << std::endl;
    std::cout << "------------#################--------" << std::endl;
    std::cout << "clap2 hitpoint: " << clap2.getHitPoint() << std::endl;
    std::cout << "clap2 enrgy po: " << clap2.getEnrgPoint() << std::endl;
    std::cout << "clap2 attDamag: " << clap2.getAttDamagePoint() << std::endl;
    std::cout << "------------#################--------" << std::endl;
    return 0;
}