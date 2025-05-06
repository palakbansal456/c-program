#include <iostream>
using namespace std;

class Counter {
private:
    static int count;  // Static data member to count objects

public:
    // Constructor increases the count when an object is created
    Counter() {
        count++;
    }

    // Static method to return the current count
    static int getCount() {
        return count;
    }
};

// Define and initialize the static data member
int Counter::count = 0;

int main() {
    // Create some Counter objects
    Counter c1, c2, c3;

    // Display number of objects created
    cout << "Number of Counter objects created: " << Counter::getCount() << endl;

    return 0;
}
