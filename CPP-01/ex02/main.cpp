/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:50:49 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 05:02:00 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
    std::string myString = "HI THIS IS BRAIN";
    std::string *stringPTR = &myString;
    std::string &stringREF = myString;

    std::cout << "< ---------------- Printing memory addresses ----------------  >" << std::endl;
    std::cout << "Original String Addr: " << &myString << std::endl;
    std::cout << "Pointer             : " << &stringPTR << std::endl;
    std::cout << "Reference           : " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "< ---------------- Printing values ----------------  >" << std::endl;
    std::cout << "Original String value: " << myString << std::endl;
    std::cout << "Pointer         value: " << stringPTR << std::endl;
    std::cout << "Reference       value: " << stringREF << std::endl;

    return (0);
}