#include <iostream>
#include <vector>
using namespace std;

// Matrix class template
template <typename T>
class Matrix {
private:
    vector<vector<T>> mat;   // 2D vector to store matrix data
    size_t rows, cols;       // Number of rows and columns

public:
    // Constructor to initialize matrix with dimensions and values
    Matrix(size_t r, size_t c) : rows(r), cols(c) {
        mat.resize(r, vector<T>(c));
    }

    // Function to input matrix values
    void inputMatrix() {
        cout << "Enter elements of " << rows << "x" << cols << " matrix:" << endl;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cin >> mat[i][j];
            }
        }
    }

    // Function to display the matrix
    void displayMatrix() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function template to add two matrices
    Matrix<T> add(const Matrix<T>& other) {
        if (this->rows != other.rows || this->cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match for addition.");
        }

        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.mat[i][j] = this->mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    // Function template to multiply two matrices
    Matrix<T> multiply(const Matrix<T>& other) {
        if (this->cols != other.rows) {
            throw invalid_argument("Matrix dimensions must match for multiplication.");
        }

        Matrix<T> result(this->rows, other.cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                result.mat[i][j] = 0;
                for (size_t k = 0; k < this->cols; ++k) {
                    result.mat[i][j] += this->mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }
};

// Main program to demonstrate matrix operations
int main() {
    try {
        // Create matrices of type int (can be changed to float, double, etc.)
        Matrix<int> mat1(2, 2); // 2x2 matrix
        Matrix<int> mat2(2, 2); // 2x2 matrix

        // Input matrices
        mat1.inputMatrix();
        mat2.inputMatrix();

        // Display matrices
        cout << "\nMatrix 1:" << endl;
        mat1.displayMatrix();

        cout << "\nMatrix 2:" << endl;
        mat2.displayMatrix();

        // Matrix addition
        Matrix<int> sum = mat1.add(mat2);
        cout << "\nSum of matrices:" << endl;
        sum.displayMatrix();

        // Matrix multiplication
        Matrix<int> product = mat1.multiply(mat2);
        cout << "\nProduct of matrices:" << endl;
        product.displayMatrix();

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
