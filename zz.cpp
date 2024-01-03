#include <iostream>

class MyBaseClass {
    private:
        int value;

        // Private default constructor
        MyBaseClass() {
            std::cout << "MyBaseClass private default constructor called." << std::endl;
        }

    protected:
        // Protected constructor with parameters
        MyBaseClass(int val) : value(val) {
            std::cout << "MyBaseClass protected constructor called. Value: " << value << std::endl;
        }

    public:
        // Public method to access the private member
        int getValue() const {
            return value;
        }
};

class MyDerivedClass : public MyBaseClass {
    private:
        int derivedValue;

    public:
        MyDerivedClass(void)
        {
            
            std::cout << "MyDerivedClass default constructor called." std::endl;
        }
        // Constructor initializing MyBaseClass
        MyDerivedClass(int valBase, int valDerived) : MyBaseClass(valBase), derivedValue(valDerived) {
            std::cout << "MyDerivedClass constructor called. Derived Value: " << derivedValue << std::endl;
        }

        // Public method to access the derived member
        int getDerivedValue() const {
            return derivedValue;
        }
};

int main() {
    // Creating an object of the derived class
    MyDerivedClass derivedObj(42, 99);
    MyDerivedClass derivedObj;

    // Accessing base class member through the derived class
    std::cout << "Value of MyBaseClass in MyDerivedClass: " << derivedObj.getValue() << std::endl;

    // Accessing derived class member
    std::cout << "Derived Value in MyDerivedClass: " << derivedObj.getDerivedValue() << std::endl;

    return 0;
}
