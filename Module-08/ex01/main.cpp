/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:35:12 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/23 21:06:43 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


void printer(const std::vector<int>& coll) {
    std::cout << "# vector = { ";
    for (std::vector<int>::const_iterator it = coll.begin(); it != coll.end(); ++it)
    {
        if (it != coll.begin())
            std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "}" << std::endl;
}

int main()
{
    Span sp = Span(100);

    try {
        // sp.rangeFiller();
        sp.addNumber(20);
        sp.addNumber(72);
        sp.addNumber(293);
        sp.addNumber(2083);
        sp.addNumber(4228);
        sp.addNumber(9873);
        sp.addNumber(9023);
        sp.addNumber(2398);
        sp.addNumber(2233);
        sp.addNumber(0);
        std::cout << "The shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "The longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Some kin" << std::endl;
    }

    {
        std::vector<int> rangeS;
        std::srand(static_cast<unsigned int>(std::time(0)));
        for (size_t i = 0; i < 4; i++) // generating and filling (from the back) it with 10 random values
        {
            int rand = std::rand() % 20;
            rangeS.push_back(rand);
        }
        printer(rangeS);
        std::vector<int>::iterator it = rangeS.begin();
        std::vector<int>::iterator ite = rangeS.end();
        sp.rangeFiller(it, ite);
        printer(sp.getVector());
        std::cout << "The shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "The longest span: " << sp.longestSpan() << std::endl;
    }
    return 0;
}