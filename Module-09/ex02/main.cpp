/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 07:40:44 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/22 07:12:49 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<unsigned int> split(std::string str, char delimiter) {
    std::vector<unsigned int> arr;
    std::string elem;
    unsigned int       value;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == delimiter) {
            std::istringstream(elem) >> value;
            arr.push_back(value);
            elem = "";
        } else {
            elem += str[i];
        }
    }
    std::istringstream(elem) >> value;
    arr.push_back(value); // Add the last element
    return arr;
}


int main(int ac, char** av) {
    try {
        if (ac < 2)
            PmergeMe::NotEnoughParams();
        for (int i = 1; i < ac; i++) {
            if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos)
                PmergeMe::InvalidInput();
        }
        PmergeMe obj;
        std::vector<unsigned int> vect;
        std::list<unsigned int> lst;
        for (int i = 1; i < ac; i++) {
            std::vector<unsigned int> tmp = split(std::string(av[i]), ' ');
            vect.insert(vect.end(), tmp.begin(), tmp.end());
            lst.insert(lst.end(), tmp.begin(), tmp.end());
        }
        // printVector(vect);
        // printList(lst);
        // std::clock_t start = std::clock();

        // storage = mergeInsertList(storage);

        // double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;
        obj.MIsortVector(vect);
        obj.MIsortList(lst);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
