/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 05:17:12 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/29 08:17:45 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <ctime>
# include <string>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <exception>
# include <vector>

void printer(std::vector<int> vec) {
    std::cout << "\nvec = {";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        if (it != vec.begin())
            std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "}\n";
}

/* insertion sort: 
    -> runs on O(n^2) -> 2 loops - BAD on large data set!
*/
void    insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int tmp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > tmp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

void    mergeHelper(std::vector<int>& l_vec, std::vector<int>& r_vec, std::vector<int>& arr) {
    int l_len = l_vec.size();
    int r_len = r_vec.size();
    int a = 0, l = 0, r = 0;

    // insertionSort(l_vec);
    // insertionSort(r_vec);
    while (l < l_len && r < r_len) {
        if (l_vec[l] < r_vec[r])
            arr[a] = l_vec[l++];
        else
            arr[a] = r_vec[r++];
        a++;
    }
    while (l < l_len) {
        arr[a] = l_vec[l++];
        a++;
    }
    while (r < r_len) {
        arr[a] = r_vec[r++];
        a++;
    }
}
void    MergeingSort(std::vector<int>& arr) {
    if (arr.size() <= 1)
        return ;
    size_t i=0;
    std::vector<int> r_vec;
    std::vector<int> l_vec;
    size_t mdPoint = arr.size() / 2;
    for ( ; i < arr.size(); i++)
    {
        if (i < mdPoint) {
            l_vec.push_back(arr[i]);
        } else {
            r_vec.push_back(arr[i]);
        }
    }
    MergeingSort(l_vec); 
    MergeingSort(r_vec);
    mergeHelper(l_vec, r_vec, arr);
}

int main(void) {
    std::vector<int> vec;

    std::srand(time(0));
    int rand;
    for (size_t i = 0; i < 50; i++)
    {
        rand = std::rand() % 100;
        vec.push_back(rand);
    }
    std::cout << "---------- insertion sort --------- \n";
    printer(vec);
    // insertionSort(vec);
    MergeingSort(vec);
    std::cout << "---------- After insertion sort --------- \n";
    printer(vec);
}