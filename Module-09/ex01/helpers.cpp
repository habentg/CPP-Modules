/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:32:56 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/29 01:28:15 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::deque<std::string> split(std::string& str, char delimiter) {
    std::deque<std::string> arr;
    std::string elem;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == delimiter) {
            arr.push_back(elem);
            elem = "";
        } else {
            elem += str[i];
        }
    }
    arr.push_back(elem); // Add the last element
    return arr;
}

std::string trim(std::string& str) {
    int len = str.length();
    int i = 0;
    for (; i < len; i++)
    {
        if (str[i] != ' ')
            break;
    }
    for (; len >= 0; len--)
    {
        if (str[len - 1] != ' ')
            break;
    }
    if (i >= len)
        return "";
    return  str.substr(i, len - i);
}
