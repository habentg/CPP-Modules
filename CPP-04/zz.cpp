#include <iostream>

// Example of Run Time Polymorphism
class Plygon {
    protected:
        double width;
        double height;
    public:
        Plygon() {
            width = 0;
            height = 0;
            std::cout << "Plygon constructor called\n";
        }
        Plygon(int wdth, int hght) {
            width = wdth;
            height = hght;
            std::cout << "Plygon constructor called\n";
        }
        virtual ~Plygon() {
            std::cout << "Plygon destructor called\n";
        }
        virtual void calculateArea() const
        {
            std::cout << "Area from the base!!!!" << std::endl;
        };
};

class Rectangle : public Plygon {
    public:
        Rectangle() : Plygon() {
            std::cout << "Rectangle constructor called\n";
        };
        Rectangle(double a, double b) : Plygon(a, b) {
            std::cout << "Rectangle constructor called\n";
        };
        ~Rectangle() {
            std::cout << "Rectangle constructor called\n";
        };
        void calculateArea() const {
            std::cout << "Area of rectangle is " << width * height << "\n";
        }
};

class Triangle : public Plygon {
    public:
        Triangle() : Plygon() {
            std::cout << "Triangle constructor called\n";
        };
        Triangle(double a, double b) : Plygon(a, b) {
            std::cout << "Triangle constructor called\n";
        };
        ~Triangle() {
            std::cout << "Triangle constructor called\n";
        };
        void calculateArea() const {
            std::cout << "Area of Triangle is " << 0.5 * width * height << "\n";
        }
};

class Pentagon : public Plygon {
    public:
        Pentagon() : Plygon() {
            std::cout << "Pentagon constructor called\n";
        };
        Pentagon(double a, double b) : Plygon(a, b) {
            std::cout << "Pentagon constructor called\n";
        };
        ~Pentagon() {
            std::cout << "Pentagon constructor called\n";
        };

};

int main() {
    Plygon* shapePtr0 = new Rectangle(4, 5);
    Plygon* shapePtr1 = new Triangle(4, 5);
    Plygon* shapePtr2 = new Pentagon(4, 5);
    shapePtr0->calculateArea(); 
    shapePtr1->calculateArea(); 
    shapePtr2->calculateArea(); 
    delete shapePtr0;
    delete shapePtr1;

    return 0;
}
