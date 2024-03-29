/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:01:28 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/23 09:47:19 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <exception>
# include <vector>
# include <list>
# include <map>
# include <deque>

class BitcoinExchange {
    private:
        const char*                     _inputFile;
        std::map<std::string, double>   _db_map;
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& cpy);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
    public:
        //OCF
        BitcoinExchange(const char* inputFile);
        ~BitcoinExchange(void);
        // member functions
        const char*                      getInFile(void) const;
        std::map<std::string, double>    getDBMap(void) const;
        void                             validate_calculate(void);
        double                           searchBringBVaue(std::string date);
        // exceptions
        class CantOpenFile : public std::exception {
            public:
                const char* what() const throw();
        };
        class NotPositiveNum : public std::exception {
            public:
                const char* what() const throw();
        };
        class NumTooLarge : public std::exception {
            public:
                const char* what() const throw();
        };
        class HeaderNotFound : public std::exception {
            public:
                const char* what() const throw();
        };
        class EmptyDB : public std::exception {
            public:
                const char* what() const throw();
        };
        class BadInput : public std::exception {
            public:
                const char* what() const throw();
                static std::string whatCustom(std::string val) throw();
        };
        class ValueNotGiven : public std::exception {
            public:
                const char* what() const throw();
                static std::string whatCustom(std::string val) throw();
        };
};

// helpers
std::string                 trim(std::string str);
void                        validate_date(std::string date);
double                      validate_value(std::string value);
#endif //BITCOINEXCHANGE_HPP