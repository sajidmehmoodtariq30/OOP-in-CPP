#include<iostream> 

using namespace std;

class person{
    private:
        string name;
        int age;
        string gender;
    public:
        // Getter and setters
        string getName(){
            return name;
        }
        void setName(string n){
            name = n;
        }
        int getAge(){
            return age;
        }
        void setAge(int a){
            age = a;
        }
        string getGender(){
            return gender;
        }
        void setGender(string g){
            gender = g;
        }
        // Constructors
        person(){
            name = "No name";
            age = 0;
            gender = "None";
        }
        person(int a){
            name = "No name";
            age = a;
            gender = "None";
        }
        person(string g){
            name = "No name";
            age = 0;
            gender = g;
        }
        person(string n, int a){
            name = n;
            age = a;
            gender = "None";
        }
        person(string n, int a, string g){
            name = n;
            age = a;
            gender = g;
        }

};

int main(){
    person St1("Ali",2);
    person St2("Kiran",34,"Female");
    person St3=St1;
    person St4;
   return 0;
}