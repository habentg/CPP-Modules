/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:52:42 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/23 17:34:36 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char* NoMatchFound::what() const throw(){
    return "{No Match found!}";
}

int main(void) {
    std::cout << "\n=============================== VECTOR ========================================\n";
    std::vector<int> v; // declerattion of vector container that holds int values
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (size_t i = 0; i < 10; i++) // generating and filling (from the back) it with 10 random values
    {
        int rand = std::rand() % 20;
        v.push_back(rand);
    }
    // std::cout << "size of our vector: " << v.size() << std::endl;
    // std::cout << "capacity of our vector: " << v.capacity() << std::endl;
    std::cout << " # v = { ";
    printer(v); // displaying the content of the vector
    std::cout << "}" << std::endl;
    try {
        easyfind(v, 7); // will throw an exception if the number 7 wasnt found.
        std::cout << "     => [Match found!!]" << std::endl;
    } catch (NoMatchFound &e) {
        std::cout << e.what() << std::endl;
    }
    // v.pop_back(); // removing one element from the back
    // std::cout << "size of our vector: " << v.size() << std::endl;
    // std::cout << "capacity of our vector: " << v.capacity() << std::endl;
    // v.resize(20);
    // std::cout << "size of our vector: " << v.size() << std::endl;
    // std::cout << "capacity of our vector: " << v.capacity() << std::endl;
    // v.shrink_to_fit(); // let go of the "Extra" space that the vector holds
    // std::cout << "vector after shrink: " << v.capacity() << std::endl;
    /* when reallocation happens: pointers, iterators and references are invalid */
    std::cout << "\n=============================== DEQUE ========================================\n";
    std::deque<int> deq;
    for (size_t i = 0; i < 10; i++) // generating and filling (from the back) it with 10 random values
    {
        int rand = std::rand() % 100;
        deq.push_back(rand);
    }
    for (size_t i = 0; i < 10; i++) // generating and filling (from the front) it with 10 random values
    {
        int rand = std::rand() % 100;
        deq.push_front(rand);
    }
    std::cout << " # deq = { ";
    printer(deq); // displaying the content of the deque
    std::cout << "}" << std::endl;
    try {
        easyfind(deq, 7); // will throw an exception if the number 7 wasnt found.
        std::cout << " => [Match found!!]" << std::endl;
    } catch (NoMatchFound &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n=============================== LIST ========================================\n";
    std::list<int> lst;    
    for (size_t i = 0; i < 10; i++) // generating and filling (from the back) it with 10 random values
    {
        int rand = std::rand() % 20;
        lst.push_back(rand);
    }
    std::cout << " # lst = { ";
    printer(lst); // displaying the content of the lst
    std::cout << "}" << std::endl;
    try {
        easyfind(lst, 7); // will throw an exception if the number 7 wasnt found.
        std::cout << " => [Match found!!]" << std::endl;
    } catch (NoMatchFound &e) {
        std::cout << e.what() << std::endl;
    }
    // lst methods:
        // -> Iterators
            // * iterator the normal one
            // * reverse_iterator 
            // * const_iterator (const_reverse as well)
        // Capacity
            // * size(), capacity (), resize()[considered as modifier], max_size()
        // access
            // * front(), back*()
        // Modifier
            // * push and pop front and back
            // * insert(), swap() and clear()
            // and more
    return 0;
}