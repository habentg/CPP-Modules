/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:35:03 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/17 10:32:30 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

// --------------------- Base Class --------------------
// virtual destuctor
// Base::Base(void) {
//     std::cout << " Base constructor" << std::endl;
// }
Base::~Base(void) {
    std::cout << "Base destructor" << std::endl;
}
// --------------------- Derived Class -----------------
A::A(void) {
    std::cout << "A constructor" << std::endl;
}
A::~A(void) {
    std::cout << "A destructor" << std::endl;
}
B::B(void) {
    std::cout << "B constructor" << std::endl;
}
B::~B(void) {
    std::cout << "B destructor" << std::endl;
}
C::C(void) {
    std::cout << "C constructor" << std::endl;
}
C::~C(void) {
    std::cout << "C destructor" << std::endl;
}

// methods

Base*   genA(void)
{
    return  (new A());
}
Base*   genB(void)
{
    return  (new B());
}
Base*   genC(void)
{
    return  (new C());
}

// random object generator
    // -> pretty self-explanatory really
Base*   generate(void)
{
    const char    arr[3] = {'a', 'b', 'c'};
    std::srand(static_cast<unsigned int>(std::time(0)));
    int index = std::rand() % 3; // The % 3 ensures the result is in the range [0, 2]

    switch (arr[index])
    {
        case 'a':
            return (genA());
        case 'b':
            return (genB());
        case 'c':
            return (genC());
        default:
            break;
    }
    return (NULL);
}
// Here is why we are using dynamic casting to know which object it was in that Base ptr.
    // => generally, in polymorphism, we can create a Base class pointer to hold the childrens object (a child object is also base type).
    // -> dynamic casting is used for casting the base pointer (whatever type of object its pointing to) to one of its Derived types.
    // since dynamic casting checks if the casting is possible and returns 'nullptr' if its not possible, it's a perfect case to use it here.

// identify the POINTER to an object
void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << " => The object was an instance of class 'A'" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << " => The object was an instance of class 'B'" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << " => The object was an instance of class 'C'" << std::endl;
}
// identify the REFERENCE to an object 
void    identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << " => The object was an instance of class 'A'" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << " => The object was an instance of class 'B'" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << " => The object was an instance of class 'C'" << std::endl;
}