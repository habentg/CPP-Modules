/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:19:38 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/18 19:39:54 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool    isTypeLiteral(t_type tt) {
    if (tt == NANN || tt == NANNF || tt == PINF || tt == PINFF || tt == NINF || tt == NINFF)
        return true;
    return false;
}

std::string ScalarConverter::printInt(void) const { 
    std::stringstream   ss;
    if (isTypeLiteral(this->_type) || (this->_int == -1 && (this->_int != static_cast<int>(this->_float))))
        ss << "Impossible";
    else
        ss << this->_int;
    return ss.str();
}
std::string ScalarConverter::printDouble(void) const {
    std::stringstream   ss;
    if (this->_type == NANN || this->_type == NANNF)   
        ss << "nan";
    else if (this->_type == PINF)
        ss << "+inf";
    else if (this->_type == NINF)
        ss << "-inf";
    else {
        if (this->_double - static_cast< int > ( this->_double ) == 0 )
            ss << this->_double << ".0";
        else
            ss << this->_double;
    }
    return ss.str();
}
std::string ScalarConverter::printFloat(void) const {
    std::stringstream   ss;
    
    if (isTypeLiteral(this->_type))
    {
        if (this->_type == NANN || this->_type == NANNF)   
            ss << "nanf";
        else if (this->_type == PINFF || this->_type == PINF)
            ss << "+inff";
        else if (this->_type == NINFF || this->_type == NINF)
            ss << "-inff";
    }
    else {
        std::cout << std::fixed << std::setprecision(3);
        if (this->_float - static_cast< int > ( this->_float ) == 0 )
            ss << this->_float << ".0f";
        else
            ss << this->_float << "f";
    }
    return ss.str();
}
std::string ScalarConverter::printChar(void) const {
    std::stringstream   ss;
    if (isTypeLiteral(this->_type) || (static_cast<int>(this->_char) != (this->_int)))
        ss << "Impossible";
    else if (this->_char < 32 || this->_char > 126)
        ss << "Non Displayable";
    else
        ss << "'" << this->_char << "'";
    return ss.str();
}

std::string ScalarConverter::printer(char code) const
{
    std::stringstream   ss;
    if (code == 'c')
        return (printChar());
    if (code == 'i')
        return (printInt());
    if (code == 'f')
        return (printFloat());
    if (code == 'd')
        return (printDouble());
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const ScalarConverter& conv) {
    if (conv.isImpossible())
        throw ScalarConverter::isImpossibleToDisplay();
    std::cout << "\n#--------------- Converting input to the four primitive datatypes -----------------#\n\n";
    os << "         char  : " << conv.printer('c') << "\n\n";
    os << "         int   : " << conv.printer('i') << "\n\n";
    os << "         float : " << conv.printer('f') << "\n\n";
    os << "         double: " << conv.printer('d') << "\n";
    std::cout << "\n#--------------- ------------------------------------------------ -----------------#\n";
    return os;
}