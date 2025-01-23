// Average using array
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

int average(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += array[i];
    return sum / size;
}

int main()
{
    int array[5];
    input(array, 5);
    cout << "Average is: " << average(array, 5) << endl;
    return 0;
}