#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 6, 8, 3, 2, 6, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Duplicate elements in the array are: "<<endl;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) {
                cout << arr[i] << " ";
                break;
            }
        }
    }

    return 0;
}
