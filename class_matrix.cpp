#include <iostream>
using namespace std;

class Matrix {
private:
    int data[3][3];  // 3x3 matrix

public:
    // Parameterized constructor to initialize the matrix
    Matrix(int values[3][3]) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                data[i][j] = values[i][j];
    }

    // Function to display the matrix
    void display() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    // Define a 3x3 array to pass to the constructor
    int initialValues[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Create a Matrix object with the given values
    Matrix m(initialValues);

    // Display the matrix
    m.display();

    return 0;
}
