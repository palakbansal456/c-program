#include <iostream>
using namespace std;

int main() {
    int N;

    cout << "Enter the number of even numbers to print: ";
    cin >> N;

    cout << "The first " << N << " even numbers are:\n";

    for (int i = 1; i <= N; ++i) {
        cout << i * 2 << " ";
    }

    cout << endl;
    return 0;
}
