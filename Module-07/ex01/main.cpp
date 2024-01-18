/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:36:35 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/18 12:59:19 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void    printer(T& value) {
    std::cout << value << std::endl;
}

// here instead of manually passing the length of the array:
    // we can give it using the sizeof() operator which calculates it at the spot.
int main(void) {
    std::cout << "\n\nint array:\n";
    std::cout << "---------------------------\n";
    int int_arr[] = {2, 5, 1, 56, 4, 245235235, 245, 38479};
    iter(int_arr, sizeof(int_arr) / sizeof(int_arr[0]), printer);

    std::cout << "\n\nstring array:\n";
    std::cout << "---------------------------\n";
    std::string str_arr[] = {"haben","CPP"," - ","07", "42","abu", "dhabi"};
    iter(str_arr, sizeof(str_arr) / sizeof(str_arr[0]), printer);

    std::cout << "\n\nfloat array:\n";
    std::cout << "---------------------------\n";
    float float_arr[] = {2.238, .5, 1, 56.08, 4, 245235235, 245, 38479};
    iter(float_arr, sizeof(float_arr) / sizeof(float_arr[0]), printer);
}