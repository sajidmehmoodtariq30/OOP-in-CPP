#include<iostream> 

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

void displayPass(int array[], int size, int avg)
{
    for (int i = 0; i < size; i++)
        if (array[i] >= avg)
            cout << array[i] << " ";
    cout << endl;
}

void displayFail(int array[], int size, int avg)
{
    for (int i = 0; i < size; i++)
        if (array[i] < avg)
            cout << array[i] << " ";
    cout << endl;
}

int main(){
    int avg;
    int array[15];
    input(array, 15);
    avg = average(array, 15);
    displayPass(array, 15, avg);
    displayFail(array, 15, avg);
   return 0;
}