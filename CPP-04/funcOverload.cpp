/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcOverload.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:24:50 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/05 19:28:14 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;
// Example of Compile Time Polymorphism
// function overloading -> same function name but strictly different parameters
class functionOverloadingExample
{
    public:
    // function with 1 int parameter
    void myFunc(int a)
    {
        cout << "a = " << a << "\n\n";
    }
    // myFunction with same name but 1 double parameter
    void myFunc(double a)
    {
        cout << "a =  " << a << "\n\n";
    }
    // myFunction with same name and 2 int parameters
    void myFunc(int a, int b)
    {
        cout << "a = " << a << ", b = " << b << "\n\n";
    }

};

int main()
{
    functionOverloadingExample obj;
    // Which myFunction is called will depend on the parameters passed
    // The first 'myFunc' is called
    obj.myFunc(10);
    // The second 'myFunc' is called
    obj.myFunc(10.20);
    // The third 'myFunc' is called
    obj.myFunc(100, 200);
    return 0;
}