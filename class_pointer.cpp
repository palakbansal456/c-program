#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    // Default constructor
    Point() {
        x = 0;
        y = 0;
        cout << "Default constructor called." << endl;
    }

    // Parameterized constructor
    Point(int xVal, int yVal) {
        x = xVal;
        y = yVal;
        cout << "Parameterized constructor called." << endl;
    }

    // Copy constructor
    Point(const Point &p) {
        x = p.x;
        y = p.y;
        cout << "Copy constructor called." << endl;
    }

    // Function to display the coordinates
    void display() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1;              // Default constructor
    p1.display();

    Point p2(3, 4);        // Parameterized constructor
    p2.display();

    Point p3 =
