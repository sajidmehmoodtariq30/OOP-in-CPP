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

int compare(int *array1, int *array2, int size){
    for (int i = 0; i < size; i++)
        if (*(array1+i) != *(array2+i))
            return -1;
    return 0;
}

int main(){
    int array1[7], array2[7];
    input(array1, 7);
    input(array2, 7);
    int result = compare(array1, array2, 7);
    if ( result == 0)
        cout << "Both arrays are equal";
    else if(result == -1)
        cout << "Both arrays are not equal";
   return 0;
}