/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:00:50 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/19 20:55:19 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -- canonical form
template<typename T>
Array<T>::Array(void) : _arr_size(0) {
    this->_my_arr = NULL;
    std::cout << "# Array<T> Default Constructor Called #" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : _arr_size(n) {
    this->_my_arr = new T[n];
    std::cout << "# Array<T> Parameterized Constructor Called #" << std::endl;
}

template<typename T>
Array<T>::Array(const Array& cpy) {
    std::cout << "# Array<T> Copy Operator Called #" << std::endl;
    *this = cpy;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
    std::cout << "# Array<T> Copy Assignment Operator Called #" << std::endl;
    if (this == &rhs)
        return *this;
    this->_arr_size = rhs._arr_size;
    this->_my_arr = new T[this->_arr_size];
    for (size_t i = 0; i < this->_arr_size; i++)
    {
        this->_my_arr[i] = rhs._my_arr[i];
    }
    return *this;
}

template<typename T>
Array<T>::~Array(void) {
    if (this->_my_arr)
    {
        delete [] this->_my_arr;
        this->_my_arr = NULL;
    }
    std::cout << "# Array<T> Destructor Called #" << std::endl;
}

// -- methods
template<typename T>
size_t    Array<T>::size(void) const {
    return (this->_arr_size);
}

// '<<' overloader
template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& rhs) {
    size_t size = rhs.size();
    os << "{";
    for (size_t i = 0; i < size; i++)
    {
        os << rhs._my_arr[i];
        if (i != size)
            os << ", ";
    }
    os << "}";
    return os;
}

