/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:02:45 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/03 18:31:11 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap("Clap");
    ClapTrap clap2(clap);
    ClapTrap clap3;

    clap3 = clap2;
    clap3.setName("Clap3");
    clap2.setName("Clap2");
    clap.attack(clap2.getName());
    clap2.takeDamage(5);
    clap2.takeDamage(5);
    clap2.takeDamage(5);
    clap2.beRepaired(5);
    clap2.attack(clap3.getName());
    return 0;
}