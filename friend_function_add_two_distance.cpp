#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    // Constructor to initialize distance
    Distance(int f = 0, int i = 0) : feet(f), inches(i) {}

    // Friend function declaration
    friend Distance addDistance(Distance d1, Distance d2);

    // Display function
    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

// Friend function definition
Distance addDistance(Distance d1, Distance d2) {
    int totalFeet = d1.feet + d2.feet;
    int totalInches = d1.inches + d2.inches;

    // Convert inches to feet if 12 or more
    if (totalInches >= 12) {
        totalFeet += totalInches / 12;
        totalInches %= 12;
    }

    return Distance(totalFeet, totalInches);
}

int main() {
    Distance d1(5, 8);  // 5 feet 8 inches
    Distance d2(3, 11); // 3 feet 11 inches

    Distance sum = addDistance(d1, d2);

    cout << "Distance 1: ";
    d1.display();

    cout << "Distance 2: ";
    d2.display();

    cout << "Total Distance: ";
    sum.display();

    return 0;
}
