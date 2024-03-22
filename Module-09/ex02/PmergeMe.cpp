/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 02:27:42 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/22 07:17:01 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
    
}
PmergeMe::~PmergeMe(void) {
    
}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
    *this = rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    (void)rhs;
    return *this;
}

const char* PmergeMe::NotEnoughParams::what() const throw(){
    return "not enough paramenters given!";
}
const char* PmergeMe::InvalidInput::what() const throw(){
    return "Non digit character found!";
}

void printVector(std::vector<unsigned int>& vec) {
    std::cout << "[";
    std::vector<unsigned int>::iterator it = vec.begin();
    for (; it != vec.end(); ++it) {
        if (it != vec.begin())
            std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "]\n";
}

void printList(std::list<unsigned int>& lst) {
    std::cout << "[";
    std::list<unsigned int>::iterator it = lst.begin();
    for (; it != lst.end(); ++it) {
        if (it != lst.begin())
            std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "]\n";
}
/* -----------------------------------------------------------------------------------------------------*/
/* ---------------------------------- Merge-Insertion sort --- vector ----------------------------------*/
/* -----------------------------------------------------------------------------------------------------*/

// Insertion sort function - iterate through the values while sorting in the left side
/*
    * hold the current value somewhere.
    * iterate backward from that index and insert it at its correct position
    * insertion sort is good with small number of elements.
*/

void vectorInsertionSort(std::vector<unsigned int>& vect) {
    for (size_t i = 1; i < vect.size(); i++)
    {
        unsigned int curr = vect[i];
        int j = i - 1;
        while (j >= 0 && vect[j] > curr) {
            vect[j + 1] = vect[j];
            j--;
        }
        vect[j + 1] = curr;
    }
}

/* merge sorting two arrays */
/* 
    -> these "small" arays are sorted
    -> now we want to merge them into a bigger array that holds both of them,, sorted
    -> we compare corosponding indexes, we save the smaller value and we pop it from its array. (we do this until one array is empty)
    -> the we just add the remaining ones. (we dont need to compare coz it was sorted --- remember)
*/
std::vector<unsigned int> mergeVector(std::vector<unsigned int>& leftVec, std::vector<unsigned int>& rightVec) {
    std::vector<unsigned int> result;
    // std::cout << "left: ";
    // printVector(leftVec);
    // std::cout << "right: ";
    // printVector(rightVec);
    while (!leftVec.empty() && !rightVec.empty()) {
        if (leftVec.front() <= rightVec.front()) {
            result.push_back(leftVec.front());
            leftVec.erase(leftVec.begin());
        }
        else {
            result.push_back(rightVec.front());
            rightVec.erase(rightVec.begin());
        }
    }
    while (!leftVec.empty()) {
        result.push_back(leftVec.front());
        leftVec.erase(leftVec.begin());
    }
    while (!rightVec.empty()) {
        result.push_back(rightVec.front());
        rightVec.erase(rightVec.begin());
    }
    // std::cout << " ==> Merged left and right: ";
    // printVector(result);
    return result;
}

/* recursively dividing the array into two and merging */
std::vector<unsigned int> vectorMI(std::vector<unsigned int>& vect) {
    if (vect.size() <= 10) {
        if (vect.size() <= 1)
            return vect;
        vectorInsertionSort(vect);
        return vect;
    }
    size_t mp = vect.size() / 2;
    std::vector<unsigned int> leftVec(vect.begin(), vect.begin() + mp);
    std::vector<unsigned int> rightVec(vect.begin() + mp, vect.end());
    leftVec = vectorMI(leftVec);
    rightVec = vectorMI(rightVec);
    std::vector<unsigned int> result = mergeVector(leftVec, rightVec);
    return result;
}
void PmergeMe::MIsortVector(std::vector<unsigned int>& vect) {
    std::cout << "Before = ";
    printVector(vect);
    std::clock_t start = std::clock(); // starting the  counter clock
    std::vector<unsigned int> sortedVec = vectorMI(vect);
    std::cout << "After = ";
    printVector(sortedVec);
    double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;
    std::cout << "Time to process a range of " << sortedVec.size() << " elements " 
        << "with std::vector<unsigned int> : " << time_taken << " µs" << std::endl;
}

/* -----------------------------------------------------------------------------------------------------*/
/* ---------------------------------- Merge-Insertion sort --- List ------------------------------------*/
/* -----------------------------------------------------------------------------------------------------*/
void listInsertionSort(std::list<unsigned int>& lst) {
    std::list<unsigned int>::iterator it = lst.begin();
    std::list<unsigned int>::iterator prevIt;
    it++;
    while (it != lst.end()) {
        unsigned int curr = *it;
        prevIt = it;
        it--;

        while (it != lst.begin() && *it > curr) {
            *(++it) = *prevIt;
            prevIt = it;
            it--;
        }
        *(++it) = curr;
        it = prevIt;
        it++;
    }
}

void PmergeMe::MIsortList(std::list<unsigned int>& lst) {
    (void)lst;
}