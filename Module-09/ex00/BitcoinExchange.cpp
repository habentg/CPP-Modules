/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:08:04 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/21 10:02:41 by hatesfam         ###   ########.fr       */
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
const char* BitcoinExchange::EmptyDB::what() const throw() {
    return "Database is empty.";
}
const char* BitcoinExchange::BadInput::what() const throw() {
    return "bad input.";
}
std::string BitcoinExchange::BadInput::whatCustom(std::string val) throw() {
    std::string res = std::string("bad input. => ") + val;
    return res;
}
const char* BitcoinExchange::ValueNotGiven::what() const throw() {
    return "Bitcoin ammount not given.";
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
    double                          exchRate = 0;
    while(std::getline(db_file, db_line)) {
        std::string date = db_line.substr(0, db_line.find(','));
        std::string value = db_line.substr(db_line.find(',') + 1);
        std::istringstream(value) >> exchRate;
        if (date.compare("date"))
            myMap.insert(std::make_pair(date, exchRate));
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
    std::ifstream   db_file("data.csv");
    std::string db_line;
    if (!db_file.is_open())
        throw BitcoinExchange::CantOpenFile();
    if (!std::getline(db_file, db_line))
        throw BitcoinExchange::EmptyDB();
    std::ifstream   i_file(this->_inputFile);
    std::string line;
    if (!i_file.is_open())
        throw BitcoinExchange::CantOpenFile();
    while (std::getline(i_file, line))
    {
        if (line != "")
            break ;
    }
    if (line.find('|') == std::string::npos)
        throw BitcoinExchange::HeaderNotFound();
    std::string date = trim(line.substr(0, line.find('|')));
    std::string value = trim(line.substr(line.find('|') + 1));
    if ((date.compare("date") || value.compare("value")))
        throw BitcoinExchange::HeaderNotFound();
    this->_db_map = mapper(db_file);
    while(std::getline(i_file, line)) {
        if (line == "") // to skip empty lines
            continue ;
        try {
            if (line.find('|') == std::string::npos)
                throw BitcoinExchange::BadInput::whatCustom(line);
            std::string date = trim(line.substr(0, line.find('|')));
            std::string value = trim(line.substr(line.find('|') + 1));
             if (value[0] == '\0')
                throw BitcoinExchange::ValueNotGiven::whatCustom(date);
            validate_date(date);
            double result = validate_value(value) * searchBringBVaue(date);
            std::cout << date << " => " << value << " = " << result << "\n"; 
        } catch (std::string &e) {
            std::cout << "Error: " << e << std::endl;
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}
