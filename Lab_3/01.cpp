#include<iostream> 

using namespace std;

// Task One

class Point{
private:
    int x,y;
public:
    Point(){
        x = 0;
        y = 0;
    }
    void display(){
        cout << "x: " << x << std::endl;
        cout << "y: " << y << std::endl;
    }
    // Task 02
    Point(int a, int b){
        x = a;
        y = b;
    }
    // Task 03
    Point(const Point &obj){
        x = obj.x;
        y = obj.y;
    }
    // Task 04
    ~Point(){
        cout << "Destructor is called" << endl;
    }
};


int main(){
    Point p1;
    p1.display();
    {
        Point p2(5,6);                                                                              
    }
   return 0;
}