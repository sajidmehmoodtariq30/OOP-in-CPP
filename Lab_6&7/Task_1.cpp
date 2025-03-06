#include <iostream>

using namespace std;

class Student
{
private:
    static int roll_no;
    string name;
    int *marks;

public:
    Student()
    {
        roll_no++;
        name = "";
        marks = nullptr;
    }
    static int getRollNo()
    {
        return roll_no;
    }
    string getName()
    {
        return name;
    }
    void setName()
    {
        cout << "Enter name: ";
        cin >> name;
    }
    void setMarks()
    {
        marks = new int[5];
        cout << "Enter marks of 5 subjects: ";
        for (int i = 0; i < 5; i++)
        {
            cin >> marks[i];
        }
    }
    void displayMarks()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Marks: " << marks[i] << endl;
        }
    }
};

int Student::roll_no = 0;

int main()
{
    Student S1;
    cout << "Roll No: " << Student::getRollNo() << endl;
    Student S2;
    cout << "Roll No: " << Student::getRollNo() << endl;
    return 0;
}