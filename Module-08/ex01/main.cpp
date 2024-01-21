/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:35:12 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/21 18:43:55 by hatesfam         ###   ########.fr       */
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
        sp.filler();
        printer(sp.getVector());
        std::cout << "The shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "The longest span: " << sp.longestSpan() << std::endl;
    } catch (Span::AlreadyFull &e) {
        std::cout << e.what() << std::endl;
    } catch (Span::NoNumberStored &e) {
        std::cout << e.what() << std::endl;
    } catch (Span::OnlyOneStored &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Some kin" << std::endl;
    }
    return 0;
}