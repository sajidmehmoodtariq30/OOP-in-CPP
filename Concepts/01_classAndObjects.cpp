#include<iostream> 

using namespace std;


class person{
    string name;
    int age;
    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
public:
    void display_Func(){
        display();
    }

};

int main(){
    person p1; // An object named p1 is created of class person.
    // p1.name = "John";
    // p1.age = 25;
    // p1.display();
    // All these values are private and cannot be accessed outside the class. Thus error 
    p1.display_Func();
    // This will not generate an error as display_Func is public 
   return 0;
}
//Notes
/*
    Class is a blueprint for creating objects.
    Class is a user defined data type.
    Class is a collection of data members and member functions.
    Object is something created based on class that has actual values.
    Access Specifiers:-
        Public: Members are accessible from outside the class.
        Private: Members are not accessible from outside the class.
        Protected: Members are accessible from derived classes.
    By default all members of a class are private.
    Now members that are public can be accessede from anywhere and those functions can use private members.
The concept of encapsulation states that the data should be hidden and only the functions that are public should be able to access it.
*/