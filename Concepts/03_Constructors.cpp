#include<iostream> 

using namespace std;

class Rectangle{
private:
    int length;
    int width;
public:
    // Deafult Constructor
    Rectangle(){
        length = 1;
        width = 1;
    }
    //Parameterized Constructor
    Rectangle(int l, int w){
        setLength(l);
        setWidth(w);
    }
    // Copy constructor
    Rectangle(Rectangle &r){
        length = r.length;
        width = r.width;
    }
    void setLength(int l){
        if(l < 0){
            length = 0;
        }else{
            length = l;
        }
    }
    void setWidth(int w){
        if(w < 0){
            width = 0;
        }else{
            width = w;
        }
    }
    int getLength(){
        return length;
    }
    int getWidth(){
        return width;
    }
    int area(){
        return length * width;
    }
    int perimeter(){
        return 2 * (length + width);
    }
};

int main(){

   return 0;
}

// Notes
/*
Constructors are special member functions that are always public and does not have a return type also they need not to be called bcz they are automatically invoked functions
Constructors are of four types
    Default constructors that does not have any argument, this is compulosory if we do not write any constructor than compiler itself writes it but if we write any type of constructor than writing a default constructor is compulsory for us to write
    Parameterized constructors that have arguments
    Deafult Parameterized constructor that have default arguments
    Copy constructors that have object of same class as argument
We cannot write a constructors with same arguments therefore parameterized and default parameterized cannot be written together
example of default parameterized w.r.t rectangle class is:-
    Rectangle(int l = 0, int w = 0){
        setLength(l);
        setWidth(w);
    }
*/