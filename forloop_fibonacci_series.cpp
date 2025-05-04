#include <iostream>
using namespace std;

int main() {
    int n;
    int a = 0, b = 1, next;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series up to " << endl << " terms: ";

    for (int i = 1; i <= n; ++i) {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }

    return 0;
}
