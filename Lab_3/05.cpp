#include<iostream> 

using namespace std;

class Rectangle{
private:
    int length, width;
public: 
    Rectangle(){
        length = 0;
        width = 0;
    }
    Rectangle(int l, int w){
        length = l;
        width = w;
    }
    Rectangle(const Rectangle &obj){
        length = obj.length;
        width = obj.width;
    }
    int area(){
        return length * width;
    }
    int parameter(){
        return 2 * (length + width);
    }
};

int main(){
    Rectangle r1;
    Rectangle r2(5,6);
    Rectangle r3(r2);
    cout << "Area of r1: " << r1.area() << endl;
    cout << "Parameter of r1: " << r1.parameter() << endl;
    cout << "Area of r2: " << r2.area() << endl;
    cout << "Parameter of r2: " << r2.parameter() << endl;
    cout << "Area of r3: " << r3.area() << endl;
    cout << "Parameter of r3: " << r3.parameter() << endl;
   return 0;
}