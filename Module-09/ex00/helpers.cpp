/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:01:26 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/21 10:37:07 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// std::vector<std::string> split(std::string& str, char delimiter) {
//     std::vector<std::string> arr;
//     std::string elem;
//     for (size_t i = 0; i < str.length(); ++i) {
//         if (str[i] == delimiter) {
//             arr.push_back(elem);
//             elem = "";
//         } else {
//             elem += str[i];
//         }
//     }
//     arr.push_back(elem); // Add the last element
//     return arr;
// }

std::string trim(std::string str) {
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

int     all_digits(std::string str) {
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return  0;
    }
    return  1;
    
}

bool isLeapYear(int year) {
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

void    validate_date(std::string date) {
    size_t first_hphen = date.find('-');
    size_t last_hphen = date.rfind('-');
    if (first_hphen == last_hphen)
        throw BitcoinExchange::BadInput::whatCustom(date);
    std::string str_year = date.substr(0, first_hphen);
    std::string str_month = date.substr(first_hphen + 1, last_hphen - first_hphen -1);
    std::string str_day = date.substr(last_hphen + 1);
    std::string t_year = trim(str_year);
    std::string t_month = trim(str_month);
    std::string t_day = trim(str_day);
    // std::cout << "year: [" << str_year << "] ";
    // std::cout << "month: [" << str_month << "] ";
    // std::cout << "day: [" << str_day << "]\n";
    if (t_year.length() != 4 || t_month.length() != 2 || t_day.length() != 2)
        throw BitcoinExchange::BadInput::whatCustom(date);
    if (!all_digits(str_year) || !all_digits(str_month) || !all_digits(str_day))
        throw BitcoinExchange::BadInput::whatCustom(date);
    int year = 0, month = 0, day = 0;
    std::istringstream(str_year) >> year;
    std::istringstream(str_month) >> month;
    std::istringstream(str_day) >> day;
    if ((year < 2009 || year > 2023) || (month > 12) || (day > 31))
        throw BitcoinExchange::BadInput::whatCustom(date);
    if (month == 2 && day > 28) {
        if (isLeapYear(year) && day > 29)
            throw BitcoinExchange::BadInput::whatCustom(date);
        if (!isLeapYear(year) && day > 28)
            throw BitcoinExchange::BadInput::whatCustom(date);
    }
    if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
        throw BitcoinExchange::BadInput::whatCustom(date);
    
}

double    validate_value(std::string value) {
    double    bitcoin_amount;
    char* endPtr;
    const char* c_str = value.c_str();
    bitcoin_amount = std::strtod(c_str, &endPtr);
    if (*endPtr != '\0')
        throw BitcoinExchange::BadInput::whatCustom(value);
    std::istringstream(value) >> bitcoin_amount;
    if (bitcoin_amount < 0)
        throw BitcoinExchange::NotPositiveNum();
    if (bitcoin_amount > 1000)
        throw BitcoinExchange::NumTooLarge();
    return bitcoin_amount;
}