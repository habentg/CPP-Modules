/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 07:40:44 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/30 16:04:08 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av) {
    try {
        if (ac != 2)
            throw RPN::NoOperandsGiven();
        RPN obj(av);
        // std::cout << " \n------------------------ \n";
        // int i = 1;
        // while (av[i])
        // {
        //     if (i != 1)
        //         std::cout << ", ";
        //     std::cout << "[" << av[i] << "]";
        //     i++;
        // }
        // std::cout << " \n------------------------ \n";
        std::cout << obj << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error: some other error!" << std::endl;
    }
    return 0;
}
