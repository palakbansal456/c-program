#include <iostream>
#include <vector>
using namespace std;

// Class to represent a Sparse Matrix
class SparseMatrix {
private:
    vector<vector<int>> matrix;
    int rows, cols;

public:
    // Constructor to initialize the matrix with given number of rows and columns
    SparseMatrix(int rows, int cols) : rows(rows), cols(cols) {
        matrix.resize(rows, vector<int>(cols, 0)); // Initializing all elements to 0
    }

    // Method to set an element in the matrix
    void setElement(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            matrix[row][col] = value;
        }
    }

    // Method to get an element from the matrix
    int getElement(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return matrix[row][col];
        }
        return 0;  // Return 0 if out of bounds (default behavior for sparse matrix)
    }

    // Method to display the matrix (for debugging purposes)
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Method to add two sparse matrices
    SparseMatrix add(const SparseMatrix &other) const {
        if (this->rows != other.rows || this->cols != other.cols) {
            throw invalid_argument("Matrix dimensions must be the same for addition.");
        }

        SparseMatrix result(rows, cols);

        // Perform element-wise addition
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int sum = this->getElement(i, j) + other.getElement(i, j);
                result.setElement(i, j, sum);
            }
        }

        return result;
    }

    // Method to multiply two sparse matrices
    SparseMatrix multiply(const SparseMatrix &other) const {
        if (this->cols != other.rows) {
            throw invalid_argument("Matrix multiplication is not possible. Columns of A must be equal to rows of B.");
        }

        SparseMatrix result(rows, other.cols);

        // Perform matrix multiplication
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += this->getElement(i, k) * other.getElement(k, j);
                }
                result.setElement(i, j, sum);
            }
        }

        return result;
    }
};

int main() {
    // Create two Sparse matrices: 3x3
    SparseMatrix A(3, 3);
    SparseMatrix B(3, 3);

    // Setting elements of matrix A
    A.setElement(0, 0, 1);
    A.setElement(1, 1, 2);
    A.setElement(2, 2, 3);

    // Setting elements of matrix B
    B.setElement(0, 1, 4);
    B.setElement(1, 0, 5);
    B.setElement(2, 2, 6);

    cout << "Matrix A: " << endl;
    A.display();

    cout << "Matrix B: " << endl;
    B.display();

    // Matrix addition
    SparseMatrix sum = A.add(B);
    cout << "A + B: " << endl;
    sum.display();

    // Matrix multiplication
    SparseMatrix product = A.multiply(B);
    cout << "A * B: " << endl;
    product.display();

    return 0;
}
