/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:20:31 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 20:08:33 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    const Animal* a = new Animal();
    const Animal* d = new Dog("d-dog");
    const Animal* c = new Cat();
    std::cout << "the a object type: " << a->getType() << " " << std::endl;
    std::cout << "the d object type: " << d->getType() << " " << std::endl;
    std::cout << "the c object type: " << c->getType() << " " << std::endl;
    d->makeSound(); //will output the cat sound!
    c->makeSound();
    a->makeSound();
    delete a;
    delete d;
    delete c;
    return 0;
}