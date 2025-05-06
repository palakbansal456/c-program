#include <iostream>
using namespace std;

class Box {
private:
    float length;
    float width;
    float height;

public:
    // Constructor to initialize box dimensions
    Box(float l, float w, float h) : length(l), width(w), height(h) {}

    // Friend function to calculate total volume of two boxes
    friend float totalVolume(Box b1, Box b2);
};

// Definition of the friend function
float totalVolume(Box b1, Box b2) {
    float volume1 = b1.length * b1.width * b1.height;
    float volume2 = b2.length * b2.width * b2.height;
    return volume1 + volume2;
}

int main() {
    Box box1(2.0, 3.0, 4.0);
    Box box2(1.5, 2.0, 3.0);

    float total = totalVolume(box1, box2);
    cout << "Total volume of the two boxes: " << total << endl;

    return 0;
}
