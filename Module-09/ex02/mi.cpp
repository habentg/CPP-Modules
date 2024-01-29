#include <iostream>
#include <algorithm>
#include <deque>

// Insertion sort function
void insertionSort(std::deque<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Merge function for merge operation
void merge(std::deque<int>& arr, size_t left, size_t mid, size_t right) {
    std::deque<int> L(arr.begin() + left, arr.begin() + mid + 1);
    std::deque<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    size_t i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < L.size()) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < R.size()) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Merge-insertion sort function
void mergeInsertionSort(std::deque<int>& arr, size_t left, size_t right, size_t threshold) {
    if (right - left < threshold) {
        insertionSort(arr);
    } else if (left < right) {
        size_t mid = left + (right - left) / 2;
        mergeInsertionSort(arr, left, mid, threshold);
        mergeInsertionSort(arr, mid + 1, right, threshold);
        merge(arr, left, mid, right);
    }
}

int main() {
    std::deque<int> arr;
    std::srand(time(0));
    for (size_t i = 0; i < 50; i++)
    {
        int rand = std::rand() % 100;
        arr.push_back(rand);
    }
    size_t threshold = 5; // Example threshold value

    mergeInsertionSort(arr, 0, arr.size() - 1, threshold);

    // Output the sorted array
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i != 0)
            std::cout << ", ";
        std::cout << arr[i];
    }
    std::cout << std::endl;

    return 0;
}
