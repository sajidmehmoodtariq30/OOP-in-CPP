#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    float GPA;

public:
    Student(const string &studentName, float studentGPA)
    {
        name = studentName;
        setGPA(studentGPA);
    }

    void setGPA(float studentGPA)
    {
        if (studentGPA >= 0.0 && studentGPA <= 4.0)
            GPA = studentGPA;
        else
            cout << "Invalid GPA value. It must be between 0.0 and 4.0." << endl;
    }

    float getGPA() const
    {
        return GPA;
    }

    string getName() const
    {
        return name;
    }
};

int main()
{
    Student student("Sajid Mehmood", 3.15);
    cout << "Student Name: " << student.getName() << endl;
    cout << "Student GPA: " << student.getGPA() << endl;

    student.setGPA(4.2);
    cout << "Updated Student GPA: " << student.getGPA() << endl;

    student.setGPA(3.8);
    cout << "Updated Student GPA: " << student.getGPA() << endl;

    return 0;
}
