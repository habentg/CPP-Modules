/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:42:09 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/15 15:26:30 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Example.hpp"
// #include <iostream>

// int main() {
//     Example<int> intExample(42);
//     std::cout << "Value: " << intExample.getValue() << std::endl;

//     Example<double> doubleExample(3.14);
//     std::cout << "Value: " << doubleExample.getValue() << std::endl;

//     return 0;
// }

#include <iostream>
#include <string>

int main() {
    std::string str = "3.14";

    try {
        // Convert the string to a float using std::stof
        float floatValue = std::stof(str);

        // Use the float value as needed
        std::cout << "Float value: " << floatValue << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0;
}
