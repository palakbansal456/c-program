#include <iostream>
#include <chrono>  
using namespace std;

#define SQUARE_MACRO(x) ((x) * (x))

inline int squareInline(int x) {
    return x * x;
}

int main() {
    int num = 5;

    auto startMacro = chrono::high_resolution_clock::now();
    int resultMacro = SQUARE_MACRO(num);
    auto endMacro = chrono::high_resolution_clock::now();
    chrono::duration<double> durationMacro = endMacro - startMacro;

    auto startInline = chrono::high_resolution_clock::now();
    int resultInline = squareInline(num);
    auto endInline = chrono::high_resolution_clock::now();
    chrono::duration<double> durationInline = endInline - startInline;

    cout << "Macro result: " << resultMacro << ", Time: " << durationMacro.count() << " seconds" << endl;
    cout << "Inline result: " << resultInline << ", Time: " << durationInline.count() << " seconds" << endl;

    return 0;
}
