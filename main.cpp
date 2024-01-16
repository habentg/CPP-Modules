
#include <iostream>

class BaseClass {
public:
    virtual void display() {
        std::cout << "BaseClass display()" << std::endl;
    }
};

class DerivedClass : public BaseClass {
public:
    void display() {
        std::cout << "DerivedClass display()" << std::endl;
    }
    void display2() {
        std::cout << "DerivedClass 2 display()" << std::endl;
    }
};

int main() {
    BaseClass* ptr = new DerivedClass();
    // DerivedClass* ptr = new DerivedClass();
    ptr->display(); // Calls DerivedClass display() due to polymorphism
    ptr->display2(); // Calls DerivedClass display() due to polymorphism
    delete ptr;     // Don't forget to release memory allocated with new
    return 0;
}
