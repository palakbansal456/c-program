#include <iostream>
#include <chrono>  // For performance measurement
using namespace std;

// Macro to find the maximum of two numbers
#define MAX_MACRO(a, b) ((a) > (b) ? (a) : (b))

// Inline function to find the maximum of two numbers
inline int maxInline(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int num1 = 10, num2 = 20;

    // Measure performance of macro
    auto startMacro = chrono::high_resolution_clock::now();
    int resultMacro = MAX_MACRO(num1, num2);
    auto endMacro = chrono::high_resolution_clock::now();
    chrono::duration<double> durationMacro = endMacro - startMacro;

    // Measure performance of inline function
    auto startInline = chrono::high_resolution_clock::now();
    int resultInline = maxInline(num1, num2);
    auto endInline = chrono::high_resolution_clock::now();
    chrono::duration<double> durationInline = endInline - startInline;

    // Output the results
    cout << "Macro result: " << resultMacro << ", Time: " << durationMacro.count() << " seconds" << endl;
    cout << "Inline result: " << resultInline << ", Time: " << durationInline.count() << " seconds" << endl;

    return 0;
}
