#include <iostream>
using namespace std;

int main() {
    int arr[] = {25, 10, 45, 2, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    int smallest = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    cout << "The smallest number in the array is: " << smallest << endl;

    return 0;
}
