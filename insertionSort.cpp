#include <iostream>
#include <algorithm>
#include <vector>


void printVector(std::vector<unsigned int>& vec) {
    std::cout << "Vector = [";
    std::vector<unsigned int>::iterator it = vec.begin();
    for (; it != vec.end(); ++it) {
        if (it != vec.begin())
            std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "]\n";
}

void vectorInsertionSort(std::vector<unsigned int>& vect) {
    for (size_t i = 1; i < vect.size(); i++)
    {
        unsigned int curr = vect[i];
        size_t j = i - 1;

        while (j >= 0 && vect[j] > curr) {
            vect[j + 1] = vect[j];
            j--;
        }
        vect[j + 1] = curr;
    }
}

std::vector<unsigned int> mergeVector(std::vector<unsigned int>& leftVec, std::vector<unsigned int>& rightVec) {
    std::vector<unsigned int> result;
    while (!leftVec.empty() && !rightVec.empty()) {
        if (leftVec.front() <= rightVec.front()) {
            result.push_back(leftVec.front());
            leftVec.erase(leftVec.begin());
            std::cout << "added value " << result.back() << std::endl;
        }
        else {
            result.push_back(rightVec.front());
            rightVec.erase(rightVec.begin());
            std::cout << "added value " << result.back() << std::endl;
        }
    }
    while (!leftVec.empty()) {
        result.push_back(leftVec.front());
        leftVec.erase(leftVec.begin());
            std::cout << "added value " << result.back() << std::endl;
    }
    while (!rightVec.empty()) {
        result.push_back(rightVec.front());
        rightVec.erase(rightVec.begin());
            std::cout << "added value " << result.back() << std::endl;
    }
    return result;
}

int main(void) {
    std::srand(time(0));
    std::vector<unsigned int> vect;
    // for (size_t i = 0; i < 5; i++)
    // {
    //     unsigned int rand = std::rand() % 100;
    //     vect.push_back(rand);
    // }
    // std::vector<unsigned int> vect_two;
    // for (size_t i = 0; i < 15; i++)
    // {
    //     unsigned int rand = std::rand() % 100;
    //     vect_two.push_back(rand);
    // }
    vect.push_back(1);
    vect.push_back(0);
    vectorInsertionSort(vect);
    std::cout << "vect one: ";
    printVector(vect);
    // vectorInsertionSort(vect_two);
    // std::cout << "vect two: ";
    // printVector(vect_two);
    // std::vector<unsigned int> sorted = mergeVector(vect, vect_two);
    // printVector(sorted);
}