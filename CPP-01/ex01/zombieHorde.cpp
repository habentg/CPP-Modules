/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:22:55 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 03:31:24 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde = new Zombie[N];
    if (N <= 0)
        std::cerr << "N should be greater than 0!" << std::endl;
    else
    {
        for (int i = 0; i < N; i++)
            horde[i].setName(name);
    }
    return horde;
}