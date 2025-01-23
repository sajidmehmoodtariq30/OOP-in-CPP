#include <iostream>

const int PI = 3.14159;

using namespace std;

class Circle {
private:
    double radius;
    double area;

    void calculateArea() {
        area = PI * radius * radius;
    }

public:
    void setRadius(double r) {
        radius = r;
        calculateArea();
    }

    double getArea() const {
        return area;
    }
};

int main() {
    Circle c;
    c.setRadius(5.0);
    cout << "Area of the circle: " << c.getArea() << endl;
    return 0;
}