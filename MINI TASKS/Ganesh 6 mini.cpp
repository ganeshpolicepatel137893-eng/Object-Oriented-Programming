#include <iostream>
using namespace std;

// Abstract Base Class
class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;

    virtual ~Shape() {}
};

// Derived Class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() override {
        return length * width;
    }

    double perimeter() override {
        return 2 * (length + width);
    }
};

// Derived Class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() override {
        return 3.14 * radius * radius;
    }

    double perimeter() override {
        return 2 * 3.14 * radius;
    }
};

// Main Function
int main() {
    Shape* s;
    int choice;

    cout << "Select Shape (1-Rectangle, 2-Circle): ";
    cin >> choice;

    if (choice == 1) {
        double l, w;
        cout << "Enter length and width: ";
        cin >> l >> w;
        s = new Rectangle(l, w);
    }
    else if (choice == 2) {
        double r;
        cout << "Enter radius: ";
        cin >> r;
        s = new Circle(r);
    }
    else {
        cout << "Invalid choice!";
        return 0;
    }

    cout << "Area: " << s->area() << endl;
    cout << "Perimeter: " << s->perimeter() << endl;

    delete s;
    return 0;
}
