/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:27:27 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/22 10:21:57 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* OCF */
RPN::RPN(char** av) {
    this->postFixing(av);
}
RPN::RPN(const RPN& cpy) {
    *this = cpy;
}
RPN& RPN::operator=(const RPN& rhs) {
    if (this != &rhs)
        this->_s = rhs.getStack();
    return *this;
}
RPN::~RPN(void) {
}
/* exception whats */
const char* RPN::NoOperandsGiven::what(void) const throw() {
    return "Provide Some values for Arthmetic Operation!";
}
const char* RPN::StackHasMoreThanOneValue::what(void) const throw() {
    return "Stack has more than one value left in it!";
}
const char* RPN::InvalidValue::what(void) const throw() {
    return "invalid input detected!";
}
const char* RPN::NotEnoughValuesForOp::what(void) const throw() {
    return "Not enough values for Arthimetic Operation!";
}

std::ostream&   operator<<(std::ostream& os, const RPN& obj) {
    if (obj.getStack().size() != 1)
        throw RPN::StackHasMoreThanOneValue();
    os << obj.getStack().top();
    return os;
}

/* member methods */
std::stack<double> RPN::getStack(void) const {
    return this->_s;
}

std::deque<std::string>    RPN::parser(char** av) {
    std::deque<std::string>  myDeque;
    std::string myStr = std::string(av[1]);
    std::deque<std::string> splitted = split(myStr, ' ');
    myDeque.insert(myDeque.end(), splitted.begin(), splitted.end());
    return myDeque;    
}

void RPN::doOperation(std::string& opertr) {
    if (this->_s.size() < 2)
        throw RPN::NotEnoughValuesForOp();
    double f_value = this->_s.top();
    this->_s.pop();
    double s_value = this->_s.top();
    this->_s.pop();
    if (!opertr.compare("+"))
        this->_s.push(f_value + s_value);
    else if (!opertr.compare("-"))
        this->_s.push(s_value - f_value);
    else if (!opertr.compare("/")) {
        size_t dividend = static_cast<size_t>(s_value / f_value);
        this->_s.push(dividend);
    }
    else if (!opertr.compare("*"))
        this->_s.push(s_value * f_value);
}

void printDeque(std::deque<std::string>& dq) {
    std::cout << "deque = [";
    std::deque<std::string>::iterator it = dq.begin();
    for (; it != dq.end(); ++it) {
        if (it != dq.begin())
            std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "]\n";
}

/* RPN calculation explanation - Briefly: 
    => all the operators and operands are in an "array" i.e, splitted by equal and trimmed;
    => Iterating through the array:
        # if its a value add it to the stack
        # if its a an Operator go do the operation of the top two values of the stack
            - if there ar not at least two values, throw an exception!
        # if its niether, throw an exception. 
    => Finally, there should be only one value in the stack! if not throw an error!
*/
void    RPN::postFixing(char** av) {
    std::deque<std::string> myDeque = parser(av);
    // printDeque(myDeque); 
    for (std::deque<std::string>::iterator it = myDeque.begin(); it != myDeque.end(); it++)
    {
        if (*it == "")
            continue ;
        char    *endPtr;
        double  operand = std::strtod((*it).c_str(), &endPtr);
        if (*endPtr != '\0') {
            if (!(*it).compare("+") || !(*it).compare("-") || !(*it).compare("*") || !(*it).compare("/"))
                doOperation(*it);
            else
                throw RPN::InvalidValue();
        } else {
            // std::cout << "value: " << *it << std::endl;
            this->_s.push(operand);
        }
    }
}
