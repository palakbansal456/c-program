#include <iostream>
using namespace std;

// A callback function
void greetEnglish() {
    cout << "Hello!" << endl;
}

void greetSpanish() {
    cout << "¡Hola!" << endl;
}

void greetFrench() {
    cout << "Bonjour!" << endl;
}

// Function that takes a function pointer (callback)
void greetUser(void (*greetFunc)()) {
    cout << "Greeting message: ";
    greetFunc();  // Call the passed-in function
}

int main() {
    // Calling greetUser with different callbacks
    greetUser(greetEnglish);
    greetUser(greetSpanish);
    greetUser(greetFrench);

    return 0;
}
