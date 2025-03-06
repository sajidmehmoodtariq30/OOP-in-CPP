#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data;

    void allocateMemory() {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    void deallocateMemory() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        allocateMemory();
    }

    ~Matrix() {
        deallocateMemory();
    }

    void inputMatrix() {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    void printMatrix() const {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    void calculateRowSums() const {
        cout << "Row sums:" << endl;
        for (int i = 0; i < rows; ++i) {
            int sum = 0;
            for (int j = 0; j < cols; ++j) {
                sum += data[i][j];
            }
            cout << "Row " << i + 1 << ": " << sum << endl;
        }
    }

    void calculateColumnSums() const {
        cout << "Column sums:" << endl;
        for (int j = 0; j < cols; ++j) {
            int sum = 0;
            for (int i = 0; i < rows; ++i) {
                sum += data[i][j];
            }
            cout << "Column " << j + 1 << ": " << sum << endl;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    Matrix mat(rows, cols);
    mat.inputMatrix();
    mat.printMatrix();
    mat.calculateRowSums();
    mat.calculateColumnSums();

    return 0;
}
