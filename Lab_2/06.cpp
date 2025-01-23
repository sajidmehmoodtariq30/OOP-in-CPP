#include<iostream> 
#include<string>
#include<ctime>

using namespace std;

class UpperCase {
private:
    string name;
    string changetoUpperCase(){
        string name = getName();
        for (int i = 0; i < name.length(); i++)
            name[i] = toupper(name[i]);
        return name;
    }
public:
    string getName(){
        return name;
    }
    void setName(string newName){
        cout << "Enter your name: ";
        getline(cin,newName);
        name = newName;
    }
    void display(){
        cout << changetoUpperCase();
    }
};

int main(){
    UpperCase Sajid;
    Sajid.setName("Sajid");
    Sajid.display();
   return 0;
}