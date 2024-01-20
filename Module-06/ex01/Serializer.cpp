/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:18:33 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/19 16:37:53 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// ----------- Data class ----------------
Data::Data(std::string name, int age) : _name(name), _age(age){
    // std::cout << this->_name << " Data default constructor" << std::endl;
}
// copy constructor
Data::Data(const Data& cpy) {
    // std::cout << this->_name << " Data copy constructor" << std::endl;
    *this = cpy;
}
// copy assignment operator
Data& Data::operator=(const Data& rhs) {
    // std::cout << this->_name << " Data copy Assignment Operator" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_age = rhs._age;
    }
    return *this;
}
// destuctor
Data::~Data(void) {
    // std::cout << this->_name << " Data destructor" << std::endl;
}
// return a constant string name
std::string Data::getName(void) const {
    return this->_name;
}
// returns an int
int Data::getAge(void) const {
    return this->_age;
}
// incr
// insertion (<<) overloader - basicly creating an outfile stream that cout recognizes to desplay.
std::ostream& operator<<(std::ostream& os, const Data& rhs) {
    std::stringstream ss;

    ss << "Name: " << rhs.getName() << ", Age: " << rhs.getAge();
    os << ss.str();
    return os;
}
// ----------- Serializer class ----------
Serializer::~Serializer() { 
    // std::cout << " Serializer destructor" << std::endl;
}

// actual work
// How the type-casting process actually works here:
    // -> this serialization static method is accepting an address of an object, 
    // -> then, in the binary level, we are 'treating' this address as an unsigned integer.
    // -> then we are returning this integer value.
uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t myPtr = reinterpret_cast<uintptr_t>(ptr);
    return (myPtr);
}

// the reverse process:
    // -> this deserialization static method is accepting an integer value, 
    // -> then, in the binary level, we are 'treating' this address as an address somewhere in the memory (Hexa).
    // -> then we are returning this address. Hence, its gonna give as the address of an object.
Data* Serializer::deserialize(uintptr_t raw) {
    Data* myPtr = reinterpret_cast<Data*>(raw);
    return (myPtr);
    
}

// this process is used when we are transfering any kind of file over a network,
// we need to convert it to the targets acceptable format specifically or to some GENERALLY acceptable format such as JSON, YAML ... 