#include<iostream> 

using namespace std;

class Circle{
    private:
        double radius;
        string color;
    public:
        Circle(){
            radius = 22/7;
            color = "red";
        }
        Circle(double r, string c){
            radius = r;
            color = c;
        }
};

int main(){
    Circle c1[10];
   return 0;
}