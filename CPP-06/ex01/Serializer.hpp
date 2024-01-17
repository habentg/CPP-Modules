/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:13:12 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/17 08:17:57 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdint> 

// non empty Data class
    // => we need the name and age in order for the object to be instantiated
class Data
{
    protected:
        std::string _name;
        int         _age;
        Data(void);
    public:
        Data(std::string name, int age);
        Data(const Data& cpy);
        Data&   operator=(const Data& rhs);
        ~Data(void);
        // getters
        std::string getName(void) const;
        int         getAge(void) const;
};

// an object shouldnt be instantiated with this class
// only job:
    // => to convert a local format to a general/file/network format --- Serialization
    // => to extract the raw data from the network format so it can be used locally ---- Deserialization
class Serializer
{
    private:
        Serializer(void);
        Serializer(const Serializer& cpy);
        Serializer&   operator=(const Serializer& rhs);
    public:
        ~Serializer(void);
        // member function
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};

std::ostream& operator<<(std::ostream& os, const Data& rhs);
#endif // !SERIALIZER_HPP