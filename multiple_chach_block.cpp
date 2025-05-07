#include <iostream>
#include <stdexcept>
using namespace std;

void testException(int code) {
    if (code == 1) {
        throw 100; // int exception
    } else if (code == 2) {
        throw string("String exception occurred."); // string exception
    } else if (code == 3) {
        throw runtime_error("Standard runtime error."); // std exception
    } else {
        cout << "No exception thrown." << endl;
    }
}

int main() {
    int choice;
    cout << "Enter 1, 2, or 3 to throw different types of exceptions: ";
    cin >> choice;

    try {
        testException(choice);
    } 
    catch (int e) {
        cout << "Caught an integer exception: " << e << endl;
    }
    catch (const string& e) {
        cout << "Caught a string exception: " << e << endl;
    }
    catch (const runtime_error& e) {
        cout << "Caught a runtime error: " << e.what() << endl;
    }
    catch (...) {
        cout << "Caught an unknown exception." << endl;
    }

    return 0;
}
