#include <iostream>
using namespace std;

int main() {
    cout << "Prime numbers between 1 and 100 are: "<<endl;

    for (int x = 2; x <= 100; ++x) {
        bool isPrime = true;

        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << x << " ";
        }
    }

    cout << endl;
    return 0;
}
