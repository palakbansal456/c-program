#include <iostream>
using namespace std;

// Function template to find maximum
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Test with integers
    cout << "Max(10, 20) = " << findMax(10, 20) << endl;

    // Test with doubles
    cout << "Max(3.14, 2.72) = " << findMax(3.14, 2.72) << endl;

    // Test with characters
    cout << "Max('a', 'z') = " << findMax('a', 'z') << endl;

    // Test with strings
    cout << "Max(\"Apple\", \"Banana\") = " << findMax(string("Apple"), string("Banana")) << endl;

    return 0;
}
