#include <iostream>

using namespace std;
class Student
{
private:
    string name;
    int age;

public:
    void setName(string newName)
    {
        name = newName;
    }

    void setAge(int newAge)
    {
        if (newAge >= 1 && newAge <= 100)
        {
            age = newAge;
        }
        else
        {
            cout << "Invalid age. Please enter an age between 1 and 100." << endl;
        }
    }

    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    Student S1;
    S1.setName("Sajid Mehmood");
    S1.setAge(18);
    S1.display();

    S1.setAge(150);
    S1.display();

    return 0;
}