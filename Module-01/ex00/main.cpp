/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:29:34 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/27 09:20:08 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "Zombie on the stack:" << std::endl;
    Zombie zombie1("zombieStack");
    zombie1.announce();
    
    std::cout << "Zombie on the Heap:" << std::endl;
    Zombie *zombieHeap1= new Zombie("zombieHeap1");
    zombieHeap1->announce();
    delete zombieHeap1;
    Zombie *zombieHeap2 = newZombie("zombieHeap2");
    delete zombieHeap2;
    randomChump("RandomHeap3");
    return (0);
}