#include <iostream>

using namespace std;

int main()
{
    int array1[7], array2[7];
    for (int i = 0; i < 7; i++)
    {
        array1[i] = i + 1;
        array2[i] = array1[i] * array1[i];
    }
    for (int i = 0; i < 7; i++)
        cout << "Square of " << array1[i] << " is " << array2[i] << endl;

    return 0;
}