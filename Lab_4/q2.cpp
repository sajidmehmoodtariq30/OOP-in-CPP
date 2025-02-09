#include <iostream>

using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int **data;

    void allocateMemory()
    {
        data = new int *[rows];
        for (int i = 0; i < rows; ++i)
        {
            data[i] = new int[cols];
        }
    }

    void deallocateMemory()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] data[i];
        }
        delete[] data;
    }

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        allocateMemory();
    }

    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
    {
        allocateMemory();
        copyFrom(other);
    }

    ~Matrix()
    {
        deallocateMemory();
    }

    void copyFrom(const Matrix &other)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }

    void setValue(int r, int c, int value)
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            data[r][c] = value;
        }
    }

    int getValue(int r, int c) const
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            return data[r][c];
        }
        return -1;
    }

    void print() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix mat1(2, 3);
    mat1.setValue(0, 0, 1);
    mat1.setValue(0, 1, 2);
    mat1.setValue(0, 2, 3);
    mat1.setValue(1, 0, 4);
    mat1.setValue(1, 1, 5);
    mat1.setValue(1, 2, 6);

    Matrix mat2(mat1); // Copy constructor
    Matrix mat3(2, 3);
    mat3.copyFrom(mat1); // Using copyFrom function

    cout << "Matrix 1:" << endl;
    mat1.print();

    cout << "Matrix 2:" << endl;
    mat2.print();

    cout << "Matrix 3:" << endl;
    mat3.print();

    return 0;
}
