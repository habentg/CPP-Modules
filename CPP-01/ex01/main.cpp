/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:29:34 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/29 18:05:09 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *horde = zombieHorde(5, "zombieHorde");
    for (int i = 0; i < 5; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}