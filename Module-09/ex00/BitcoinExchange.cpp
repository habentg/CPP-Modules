/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:08:04 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/28 07:37:52 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
/* Ortodox Canonical Form */
BitcoinExchange::BitcoinExchange(const char* inputFile) {
    this->_inputFile = inputFile; 
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy) {
    *this = cpy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    if (this != &rhs)
    {
        this->_inputFile = rhs.getInFile();
        this->_db_map = rhs.getDBMap();
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {
}

/* member methods implementation */
const char*    BitcoinExchange::getInFile(void) const {
    return this->_inputFile;
}

std::map<std::string, double> BitcoinExchange::getDBMap(void) const {
    return this->_db_map;
}
/* overiding the 'what()' in std::exception */
const char* BitcoinExchange::NotPositiveNum::what() const throw() {
    return "not a positive number.";
}
const char* BitcoinExchange::CantOpenFile::what() const throw() {
    return "could not open file.";
}
const char* BitcoinExchange::NumTooLarge::what() const throw() {
    return "too large a number.";
}
const char* BitcoinExchange::HeaderNotFound::what() const throw() {
    return "Incorrect or header not found.";
}
// const char* BitcoinExchange::BadInput::what() const throw() {
//     return "bad input.";
// }
std::string BitcoinExchange::BadInput::whatCustom(std::string val) throw() {
    std::string res = std::string("bad input. => ") + val;
    return res;
}
std::string BitcoinExchange::ValueNotGiven::whatCustom(std::string val) throw() {
    std::string res = std::string("Bitcoin ammount not given => ") + val;
    return res;
}

/* puts all the date-exchange value pairs in a map:
    a map is a container that holds its value in a sorted (unique)key-value pair manner */
std::map<std::string, double>   mapper(std::ifstream&   db_file) { 
    std::map<std::string, double>   myMap;
    std::vector<std::string>        arr;
    std::string                     db_line;
    double                          d;
    while(std::getline(db_file, db_line)) {
        arr = split(db_line, ',');
        std::istringstream(arr[1]) >> d;
        if (arr[0].compare("date"))
            myMap.insert(std::make_pair(arr[0], d)); // comeback to this, string-double, think about it
    }
    return myMap;
}

/* gonna search in the map and bring the value basically*/
/* How lower_bound method works:
    # it will return an iterator to a Key-Value pair thats EQUAL OR GREATER than the target date.
   But then we are manually pulling back to the previous pair if our target is not the first or the target is not the one we "found"
*/
double  BitcoinExchange::searchBringBVaue(std::string date) {
    std::map<std::string, double> dateMap = this->getDBMap();
    std::map<std::string, double>::iterator it = dateMap.lower_bound(date);
    if (it == dateMap.begin() || it->first != date) {
        --it;
    }
    return it->second;   
}

/* input file and the csv file check && calculate*/
void    BitcoinExchange::validate_calculate(void) {
    std::ifstream   i_file(this->_inputFile);
    if (!i_file.is_open())
        throw BitcoinExchange::CantOpenFile();
    std::ifstream   db_file("data.csv");
    if (!db_file.is_open())
        throw BitcoinExchange::CantOpenFile();
    this->_db_map = mapper(db_file);
    // std::cout << "Map elements:" << std::endl;
    // for (std::map<std::string, double>::iterator it = this->_db_map.begin(); it != this->_db_map.end(); ++it) {
    //     std::cout << it->first << " => " << it->second << std::endl;
    // }
    std::string line;
    std::getline(i_file, line);
    std::vector<std::string> arr = split(line, '|');
    if (arr.size() != 2 || (trim(arr[0]).compare("date") || trim(arr[1]).compare("value")))
        throw BitcoinExchange::HeaderNotFound();
    while(std::getline(i_file, line)) {
        std::vector<std::string> arr = split(line, '|');
        try {
            if (arr.size() != 2)
                throw BitcoinExchange::BadInput::whatCustom(line);
            std::string trimmed_date = trim(arr[0]);
            std::string trimmed_value = trim(arr[1]);
             if (trimmed_value[0] == '\0')
                throw BitcoinExchange::ValueNotGiven::whatCustom(trimmed_date);
            validate_date(trimmed_date);
            double result = validate_value(trimmed_value) * searchBringBVaue(trimmed_date);
            std::cout << trimmed_date << " => " << trimmed_value << " = " << result << "\n"; 
        } catch (std::string &e) {
            std::cout << "Error: " << e << std::endl;
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}
