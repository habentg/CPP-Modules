/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:48:33 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/19 16:40:46 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    std::string name = std::string("Haben");
    Data* ourData = new Data(name, 24);

    std::cout << "\n----------------Serializing---------------------\n" << std::endl;
    std::cout << "\nOriginal Data: " << *ourData << std::endl;
    uintptr_t ptr = Serializer::serialize(ourData);
    std::cout << "\nunsigned long format: [" << ptr << "]\n";

    std::cout << "\n----------------Deserializing-------------------\n" << std::endl;
    std::cout << "\nunsigned long format: [" << ptr << "]\n";
    Data* deserializedData = Serializer::deserialize(ptr);
    std::cout << "\nOriginal Data: " << *deserializedData << std::endl;    
    std::cout << std::endl;
    
    delete  ourData;    
}