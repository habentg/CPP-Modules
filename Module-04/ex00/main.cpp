/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:20:31 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 20:02:58 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void)
{
    const Animal* a = new Animal();
    const Animal* d = new Dog();
    const Cat* c = new Cat();
    std::cout << std::endl;
    std::cout << "the a object type: " << a->getType() << " and it sounds as: ";
    a->makeSound();
    std::cout << std::endl;
    std::cout << "the d object type: " << d->getType() << " and it sounds as: ";
    d->makeSound();
    std::cout << std::endl;
    std::cout << "the c object type: " << c->getType() << " and it sounds as: ";
    c->makeSound();
    std::cout << std::endl;
    delete a;
    delete d;
    delete c;

    std::cout << "\n------------------ wrong animal/cat --------------" << std::endl;
    const WrongAnimal* w_a = new WrongAnimal();
    const WrongCat* w_c = new WrongCat();
    std::cout << std::endl;
    std::cout << "the w_a object type: " << w_a->getType() << " and it sounds as: ";
    w_a->makeSound();
    std::cout << std::endl;
    std::cout << "the w_c object type: " << w_c->getType() << " and it sounds as: ";
    w_c->makeSound();
    std::cout << std::endl;
    delete w_a;
    delete w_c;
    return 0;
}