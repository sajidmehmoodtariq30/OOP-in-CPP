#include <iostream>
using namespace std;

class StudentMarks
{
private:
    int *marks;
    int n;

public:
    StudentMarks(int numStudents)
    {
        n = numStudents;
        marks = new int[n];
        inputMarks();
    }

    void inputMarks()
    {
        cout << "Enter the marks of students: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Student " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    double calculateAverage()
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += marks[i];
        }
        return static_cast<double>(sum) / n;
    }

    int findHighest()
    {
        int highest = marks[0];
        for (int i = 1; i < n; i++)
        {
            if (marks[i] > highest)
            {
                highest = marks[i];
            }
        }
        return highest;
    }

    void displayResults()
    {
        cout << "\nAverage Marks: " << calculateAverage() << endl;
        cout << "Highest Marks: " << findHighest() << endl;
    }

    ~StudentMarks()
    {
        delete[] marks;
    }
};

int main()
{
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    StudentMarks sm(n);

    sm.displayResults();

    return 0;
}
