/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:36:58 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/21 18:54:07 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int size) : _max_size(size) {

}

Span::Span(const Span& cpy) {
    *this = cpy;
}

Span& Span::operator=(const Span& rhs) {
    if (this != &rhs)
        this->_max_size = rhs.getMaxSize();
    return *this;
}

Span::~Span(void) {
    
}

// getter methods
/* we have to set the returned vector so the caller cant modify it */
const std::vector<int>& Span::getVector(void) const {
    return this->_v;
}

unsigned int    Span::getMaxSize(void) const {
    return this->_max_size;
}
// exception handler

const char* Span::AlreadyFull::what() const throw() {
    return "Array is full, cant add numbers elemets!";
}

const char* Span::NoNumberStored::what() const throw() {
    return "Array is Empty!";
}
const char* Span::OnlyOneStored::what() const throw() {
    return "Array should at least have two elements!";
}
// member methods

void    Span::addNumber(int value) {
    if (this->_v.size() >= this->_max_size)
        throw AlreadyFull();
    this->_v.push_back(value);
}

unsigned int Span::shortestSpan(void) {
    unsigned int dist = UINT_MAX;
    
    if (this->_v.empty())
        throw NoNumberStored();
    if (this->_v.size() == 1)
        throw OnlyOneStored();
    std::vector<int>::iterator o_it = this->_v.begin();
    for (; o_it != this->_v.end(); ) {
        std::vector<int>::iterator i_it = o_it + 1;
        for (; i_it != this->_v.end(); ++i_it) {
            if (static_cast<unsigned int>(std::abs(*o_it - *i_it)) < dist)
                dist = std::abs(*o_it - *i_it);
        }
        ++o_it;
    }
    return dist;
}

unsigned int Span::longestSpan(void) {
    unsigned int dist = 0;
    
    if (this->_v.empty())
        throw NoNumberStored();
    if (this->_v.size() == 1)
        throw OnlyOneStored();
    std::vector<int>::iterator o_it = this->_v.begin();
    for (; o_it != this->_v.end(); ) {
        std::vector<int>::iterator i_it = o_it + 1;
        for (; i_it != this->_v.end(); ++i_it) {
            if (static_cast<unsigned int>(std::abs(*o_it - *i_it)) > dist)
                dist = std::abs(*o_it - *i_it);
        }
        ++o_it;
    }
    return dist;
}

void Span::filler(void) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (size_t i = 0; i < this->_max_size; i++)
    {
        int rand = std::rand() % 1000;
        this->addNumber(rand);
    }
    // this->_v.shrink_to_fit();
    std::cout << "size of our vector: " << this->_v.size() << std::endl;
    std::cout << "capacity of our vector: " << this->_v.capacity() << std::endl;
}