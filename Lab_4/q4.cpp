#include <iostream>

using namespace std;

class DynamicArray {
private:
    int* array;
    int size;
    bool isShallowCopy;

public:
    // Programmer-defined constructor to initialize the array with a given size
    DynamicArray(int s) : size(s), isShallowCopy(false) {
        array = new int[size];
        cout << "Array of size " << size << " created." << endl;
    }

    // Copy constructor to perform a deep copy or shallow copy based on the flag
    DynamicArray(const DynamicArray& other, bool shallow = false) : size(other.size), isShallowCopy(shallow) {
        if (shallow) {
            array = other.array;
            cout << "Shallow copy performed." << endl;
        } else {
            array = new int[size];
            for (int i = 0; i < size; ++i) {
                array[i] = other.array[i];
            }
            cout << "Deep copy performed." << endl;
        }
    }

    // Destructor to deallocate the array
    ~DynamicArray() {
        if (!isShallowCopy) {
            delete[] array;
            cout << "Array of size " << size << " destroyed." << endl;
        }
    }
};

int main() {
    DynamicArray arr1(5);
    DynamicArray arr2 = DynamicArray(arr1, true); // Shallow copy
    DynamicArray arr3 = DynamicArray(arr1, false); // Deep copy

    return 0;
}