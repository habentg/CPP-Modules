/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:20:31 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 20:56:59 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    const Animal* d = new Dog();
    
    // const Cat* c = new Cat();
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "the d object type: " << d->getType() << " and it sounds as: ";
    // d->makeSound();
    // std::cout << std::endl;
    // std::cout << "the c object type: " << c->getType() << " and it sounds as: ";
    // c->makeSound();
    // std::cout << std::endl;
    delete d;
    // delete c;
    return 0;
}