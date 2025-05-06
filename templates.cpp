#include <iostream>
using namespace std;

// Function template to find maximum
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Using getMax with int
    cout << "Max of 3 and 7 is: " << getMax(3, 7) << endl;

    // Using getMax with float
    cout << "Max of 3.5 and 2.1 is: " << getMax(3.5f, 2.1f) << endl;

    // Using getMax with char
    cout << "Max of 'a' and 'z' is: " << getMax('a', 'z') << endl;

    // Using getMax with string
    cout << "Max of \"apple\" and \"banana\" is: " << getMax(string("apple"), string("banana")) << endl;

    return 0;
}
