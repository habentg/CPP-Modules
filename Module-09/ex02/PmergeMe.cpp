/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 02:27:42 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/23 10:39:48 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) {
    for (int i = 1; i < ac; i++) {
        std::vector<unsigned long> tmp = split(std::string(av[i]), ' ');
        this->vect.insert(vect.end(), tmp.begin(), tmp.end());
        this->lst.insert(lst.end(), tmp.begin(), tmp.end());
    }
}
PmergeMe::~PmergeMe(void) {
    // std::cout << "Obj destructed!\n";   
}

const char* PmergeMe::NotEnoughParams::what() const throw(){
    return "not enough paramenters given!";
}
const char* PmergeMe::InvalidInput::what() const throw(){
    return "Non digit character found!";
}

std::string trim(std::string str) {
    int len = str.length();
    int i = 0;
    for (; i < len; i++)
    {
        if (str[i] != ' ')
            break;
    }
    for (; len >= 0; len--)
    {
        if (str[len - 1] != ' ')
            break;
    }
    if (i >= len)
        return "";
    return  str.substr(i, len - i);
}

std::vector<unsigned long> split(std::string str, char delimiter) {
    std::vector<unsigned long> arr;
    std::string elem;
    long long       value;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == delimiter) {
            if (trim(elem).empty())
                continue ;
            std::istringstream(elem) >> value;
            if (value > LLONG_MAX)
                throw PmergeMe::InvalidInput();
            arr.push_back(value);
            elem = "";
        } else {
            elem += str[i];
        }
    }
    if (trim(elem).empty())
        return arr;
    std::istringstream(elem) >> value;
    if (value > LLONG_MAX)
        throw PmergeMe::InvalidInput();
    arr.push_back(value); // Add the last element
    return arr;
}


void printVector(std::vector<unsigned long>& vec) {
    std::cout << "Vector: [";
    std::vector<unsigned long>::iterator it = vec.begin();
    for (; it != vec.end(); ++it) {
        if (it != vec.begin())
            std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "]\n";
}

void printList(std::list<unsigned long>& lst) {
    std::cout << "List: [";
    std::list<unsigned long>::iterator it = lst.begin();
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

void vectorInsertionSort(std::vector<unsigned long>& vect) {
    for (size_t i = 1; i < vect.size(); i++)
    {
        unsigned long curr = vect[i];
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
void mergeVector(std::vector<unsigned long>& mainVect, std::vector<unsigned long>& leftVec, std::vector<unsigned long>& rightVec) {
    while (!leftVec.empty() && !rightVec.empty()) {
        if (leftVec.front() <= rightVec.front()) {
            mainVect.push_back(leftVec.front());
            leftVec.erase(leftVec.begin());
        }
        else {
            mainVect.push_back(rightVec.front());
            rightVec.erase(rightVec.begin());
        }
    }
    while (!leftVec.empty()) {
        mainVect.push_back(leftVec.front());
        leftVec.erase(leftVec.begin());
    }
    while (!rightVec.empty()) {
        mainVect.push_back(rightVec.front());
        rightVec.erase(rightVec.begin());
    }
}

/* recursively dividing the array into two and merging */
void vectorMI(std::vector<unsigned long>& vect) {
    if (vect.size() <= 10) {
        if (vect.size() <= 1)
            return ;
        vectorInsertionSort(vect);
        return ;
    }
    size_t mp = vect.size() / 2;
    std::vector<unsigned long> leftVec(vect.begin(), vect.begin() + mp);
    std::vector<unsigned long> rightVec(vect.begin() + mp, vect.end());
    vectorMI(leftVec);
    vectorMI(rightVec);
    vect.clear();
    mergeVector(vect, leftVec, rightVec);
}
void PmergeMe::sortVector(std::vector<unsigned long>& vect) {
    clock_t start = std::clock(); // starting the  counter clock
    vectorMI(vect);
    clock_t done = std::clock(); // stoping the  counter clock
    this->vecSortingTime = static_cast<double>(done - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;
}

/* -----------------------------------------------------------------------------------------------------*/
/* ---------------------------------- Merge-Insertion sort --- List ------------------------------------*/
/* -----------------------------------------------------------------------------------------------------*/
void listInsertionSort(std::list<unsigned long>& lst) {
    std::list<unsigned long>::iterator it = lst.begin();
    std::list<unsigned long>::iterator prevIt;
    it++;
    while (it != lst.end()) {
        unsigned long curr = *it;
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

void mergeList(std::list<unsigned long>& mainList, std::list<unsigned long>& leftLst, std::list<unsigned long>& rightLst) {
    std::list<unsigned long>::iterator leftIt = leftLst.begin();
	std::list<unsigned long>::iterator rightIt = rightLst.begin();

	/* Comparing elements and sorting them */
	while (leftIt != leftLst.end() && rightIt != rightLst.end()) {
		if (*leftIt < *rightIt) {
			mainList.push_back(*leftIt);
			leftIt++;
		} else {
			mainList.push_back(*rightIt);
			rightIt++;  
		}
	}
	/* Adding remaining elements out of range */
	while (leftIt != leftLst.end()) {
		mainList.push_back(*leftIt);
		leftIt++;
	}
	while (rightIt != rightLst.end()) {
		mainList.push_back(*rightIt);
		rightIt++;
	}
}

void listMI(std::list<unsigned long>& lst) {
    if (lst.size() <= 1)
        return ;
    std::list<unsigned long>::iterator mp = lst.begin();
    std::advance(mp, lst.size() / 2);
    std::list<unsigned long> left(lst.begin(), mp);
    std::list<unsigned long> right(mp, lst.end());
    listMI(left);
    listMI(right);
    lst.clear();
    mergeList(lst, left, right);
}
void PmergeMe::sortList(std::list<unsigned long>& lst) {
    clock_t start = std::clock();  // starting the  counter clock
    listMI(lst);
    clock_t done = std::clock();  // stoping the  counter clock
    this->lstSortingTime = static_cast<double>(done - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;
}