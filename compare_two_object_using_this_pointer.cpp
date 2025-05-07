#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    // Constructor
    Counter(int c = 0) {
        count = c;
    }

    // Compare this object with another Counter object
    void compare(const Counter& other) const {
        if (this->count > other.count)
            cout << "Current object has a higher count (" << this->count << ") than other (" << other.count << ")." << endl;
        else if (this->count < other.count)
            cout << "Other object has a higher count (" << other.count << ") than current (" << this->count << ")." << endl;
        else
            cout << "Both objects have the same count (" << count << ")." << endl;
    }

    // Optional: display count
    void display() const {
        cout << "Count: " << count << endl;
    }
};

int main() {
    Counter c1(10);
    Counter c2(15);

    cout << "Comparing c1 and c2:\n";
    c1.compare(c2);  // compares using this pointer

    return 0;
}
