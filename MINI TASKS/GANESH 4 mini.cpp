#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    float x, y;

    void input() {
        cout << "Enter x and y coordinates: ";
        cin >> x >> y;
    }

    void display() {
        cout << "(" << x << ", " << y << ")";
    }

    Point operator+(Point p) {
        Point temp;
        temp.x = x + p.x;
        temp.y = y + p.y;
        return temp;
    }

    Point operator-(Point p) {
        Point temp;
        temp.x = x - p.x;
        temp.y = y - p.y;
        return temp;
    }

    float distance(Point p) {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

class Line {
public:
    Point p1, p2;

    void input() {
        cout << "\nEnter first point of line:\n";
        p1.input();

        cout << "Enter second point of line:\n";
        p2.input();
    }

    float length() {
        return p1.distance(p2);
    }

    void display() {
        cout << "Line between ";
        p1.display();
        cout << " and ";
        p2.display();
    }
};

int main() {
    Point A, B, C;

    cout << "Enter Point A\n";
    A.input();

    cout << "Enter Point B\n";
    B.input();

    C = A + B;
    cout << "\nA + B = ";
    C.display();

    C = A - B;
    cout << "\nA - B = ";
    C.display();

    cout << "\nDistance between A and B = " << A.distance(B);

    Line L;
    L.input();

    cout << "\n";
    L.display();

    cout << "\nLength of line = " << L.length();

    return 0;
}
