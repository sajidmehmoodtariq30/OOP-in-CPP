#include<iostream> 

using namespace std;

int main(){
    string name = "Sajid Mehmood";
    int age = 18;
    float cgpa = 3.15;
    string *ptrName = &name;
    int *ptrAge = &age;
    float *ptrCgpa = &cgpa;
    cout << "Name: " << *ptrName << endl;
    cout << "Age: " << *ptrAge << endl;
    cout << "CGPA: " << *ptrCgpa << endl;
    cout << "Size of of Name: " << sizeof(name) << endl;
    cout << "Size of of Age: " << sizeof(age) << endl;
    cout << "Size of of CGPA: " << sizeof(cgpa) << endl;
   return 0;
}