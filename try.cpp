
#include <iostream>
#include <string>
#include <list>

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

void listInsertionSort(std::list<unsigned int>& lst) {
    std::list<unsigned int>::iterator it = lst.begin();
    std::list<unsigned int>::iterator prevIt;
    std::list<unsigned int>::iterator tmp_it;
    it++;
    while (it != lst.end()) {
		unsigned int currVal = *it;
		tmp_it = it;
		prevIt = it--;
		it = tmp_it;

		while (prevIt != lst.begin() && *prevIt > currVal) {
			prevIt
		}
    }
}

int main(void) {
	std::list<unsigned int> lst;

	for (size_t i = 0; i < 50; i++)
    {
        int rand = std::rand() % 100;
        lst.push_back(rand);
    }
	unsigned int stagler = 0;
	
	listInsertionSort(lst);
}