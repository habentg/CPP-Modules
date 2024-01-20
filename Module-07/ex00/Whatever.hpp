/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:07:40 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/19 20:14:29 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// when passing the values to the swap template function:
    // -> we have to pass the values by reference, because we want to modify the original values (not the copies)!
template<typename T>
void   swap(T& val_1, T& val_2)
{
    T tmp = val_1;
    val_1 = val_2;
    val_2 = tmp;
    // std::cout << "value_1:" << val_1 << std::endl;
    // std::cout << "value_2:" << val_2 << std::endl;
}
template<typename T>
T   max(T val_1, T val_2)
{
    return val_1 > val_2 ? val_1 : val_2;
}
template<typename T>
T   min(T& val_1, T& val_2)
{
    return val_1 < val_2 ? val_1 : val_2;
}