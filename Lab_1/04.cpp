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

int main(){
    int temperature;
    int array[5];
    input(array, 5);
    cout << "Enter average temperature of last year";
    cin >> temperature;
    if (temperature > average(array, 5))
        cout << "Last year was hotter than average";
    else if (temperature < average(array, 5))
        cout << "Last year was colder than average";
    else
        cout << "Last year was average";
   return 0;
}