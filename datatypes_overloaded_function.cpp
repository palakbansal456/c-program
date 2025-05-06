#include <iostream>
#include <string>
using namespace std;

void print(int value) {
    cout << "Integer: " << value << endl;
}

void print(float value) {
    cout << "Float: " << value << endl;
}

void print(string value) {
    cout << "String: " << value << endl;
}

int main() {
    int i = 10;
    float f = 3.14f;
    string s = "Hello, World!";

    print(i);   // Calls print(int)
    print(f);   // Calls print(float)
    print(s);   // Calls print(string)

    return 0;
}
