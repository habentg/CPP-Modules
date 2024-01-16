/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:41:09 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/14 06:01:58 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

template <typename T>
class Example {
public:
    Example(T value);
    ~Example;
    T getValue() const;

private:
    T data;
};

// Include the template implementation (definitions) here
#include "Example.cpp"

#endif  // EXAMPLE_HPP
