#include <iostream>
using namespace std;

int main() {
    int n;
    float sum = 0.0;

    cout << "Enter the number of terms: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / i;
    }

    cout << "Sum of the harmonic series up to " << n << " terms is: " << sum << endl;

    return 0;
}
