/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:20:31 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/16 10:29:10 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    Dog d;
    Dog d1(d);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "the d object type: " << d.getType() << " and it sounds as: ";
    d.makeSound();
    std::cout << std::endl;
    std::cout << "the d object idea: " << d.getIdea(0) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "the d1 object type: " << d1.getType() << " and it sounds as: ";
    d1.makeSound();
    std::cout << std::endl;
    std::cout << "the d1 object idea: " << d1.getIdea(0) << std::endl;

    Animal* animals[6] = { new Dog(), new Dog(), new Dog(), new Cat() , new Cat(), new Cat() };
    
    for (size_t i = 0; i < 6; i++)
    {
        animals[i]->makeSound();
        delete animals[i];
    }
    
}
// int main(void)
// {
//     const Dog* d = new Dog();
//     const Dog dd;
//     const Dog ddd(dd);
//     const Cat* c = new Cat();
    
//     std::cout << std::endl;
//     std::cout << std::endl;
//     std::cout << "the d object type: " << d->getType() << " and it sounds as: ";
//     d->makeSound();
//     std::cout << std::endl;
//     std::cout << "the d object idea: " << d->getIdea(0) << std::endl;
    
//     std::cout << std::endl;
//     std::cout << "the c object type: " << c->getType() << " and it sounds as: ";
//     c->makeSound();
//     std::cout << std::endl;
//     std::cout << "the c object idea: " << c->getIdea(0) << std::endl;
//     std::cout << std::endl;
    
//     delete d;
//     delete c;
//     return 0;
// }



