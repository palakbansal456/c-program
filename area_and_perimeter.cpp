#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor to initialize the rectangle's dimensions
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    // Method to calculate the area of the rectangle
    double calculateArea() {
        return length * width;
    }

    // Method to calculate the perimeter of the rectangle
    double calculatePerimeter() {
        return 2 * (length + width);
    }

    // Method to display the rectangle's dimensions and calculated values
    void displayDetails() {
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }
};

int main() {
    // Create a Rectangle object with specific dimensions
    Rectangle rect(5.0, 3.0);

    // Display the rectangle's details
    rect.displayDetails();

    return 0;
}
