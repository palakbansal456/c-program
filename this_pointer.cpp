#include <iostream>
using namespace std;

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Constructor
    Box(double l = 1.0, double w = 1.0, double h = 1.0) {
        length = l;
        width = w;
        height = h;
    }

    // Function to set dimensions and return current object
    Box& setDimensions(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
        return *this; // return current object by reference using this pointer
    }

    // Display box dimensions
    void display() const {
        cout << "Length: " << length
             << ", Width: " << width
             << ", Height: " << height << endl;
    }
};

int main() {
    Box box;

    // Set dimensions and chain method calls (optional)
    box.setDimensions(10.5, 5.2, 3.8).display();

    return 0;
}
