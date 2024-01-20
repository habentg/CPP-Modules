/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:20:14 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/19 16:25:17 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
    : _char('\0'), _int(0), _float(0.00f), _double(0.00), _type(UNKNOWN), _impossible(false)
{ }

ScalarConverter::ScalarConverter(const ScalarConverter& cpy)
{
    *this = cpy;
}

ScalarConverter ScalarConverter::operator=(const ScalarConverter& rhs)
{
    if(this != &rhs)
    {
        this->_char = rhs._char;
        this->_int = rhs._int;
        this->_float = rhs._float;
        this->_double = rhs._double;
        this->_type = rhs._type;
        this->_impossible = rhs._impossible;
    };
    return *this;
}

ScalarConverter::~ScalarConverter()
{ }

const char* ScalarConverter::UnknownType::what() const throw()
{
    return "\nError: Unknown Datatype\n\n   ->enter char, int, float or double!!\n";
}
const char* ScalarConverter::isImpossibleToDisplay::what() const throw()
{
    return "\nError:\n\n    !!Impossible to Display!!\n";
}

void ScalarConverter::convert(const char* input)
{
    ScalarConverter conv;

    try {
        conv.setInputType(input);
        if (conv.getType() == UNKNOWN)
            throw ScalarConverter::UnknownType();
        if (conv.isImpossible())
            throw ScalarConverter::isImpossibleToDisplay();
        std::cout << conv << std::endl; // if the datatpe is known, we diplay our casted values
    } catch (ScalarConverter::UnknownType &e)
    {
        std::cout << e.what() << std::endl;
    } catch (ScalarConverter::isImpossibleToDisplay &e)
    {
        std::cout << e.what() << std::endl;
    } catch (...)
    {
        std::cout << "There is some problem!" << std::endl;
    }
}
