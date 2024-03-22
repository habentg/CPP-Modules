/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 07:40:44 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/22 10:06:37 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av) {
    try {
        if (ac != 2)
            throw RPN::NoOperandsGiven();
        if (std::string(av[1]).find_first_not_of("0123456789+-*/ ") != std::string::npos)
            throw RPN::InvalidValue();
        RPN obj(av);
        std::cout << obj << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
