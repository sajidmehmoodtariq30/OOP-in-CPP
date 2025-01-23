#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    void setName(const string &newName)
    {
        name = newName;
    }

    string getName() const
    {
        return name;
    }

    void setAge(int newAge)
    {
        age = newAge;
    }

    int getAge() const
    {
        return age;
    }
};

int main()
{
    Person person;
    person.setName("John Doe");
    person.setAge(30);

    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;

    return 0;
}