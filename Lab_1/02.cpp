// Dsplay odd number in an array of 15 elements
#include <iostream>

using namespace std;

int input(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> array[i];
    }
    return 0;
}

void displayOdd(int array[], int size)
{
    for (int i = 0; i < 15; i++)
        if (array[i] % 2 != 0)
            cout << array[i] << " ";
}

int main()
{
    int array[15];
    input(array, 15);
    cout << "Odd numbers in the array are: ";
    displayOdd(array, 15);
    return 0;
}