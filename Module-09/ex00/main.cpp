/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:00:41 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/28 06:15:46 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, const char** av) {
    try {
        if (ac != 2)
            throw BitcoinExchange::CantOpenFile();
        BitcoinExchange  obj(av[1]);
        obj.validate_calculate();
    } catch (std::string &e) {
        std::cout << "Error: " << e << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "protection!!" << std::endl;
    }
    return 0;
}