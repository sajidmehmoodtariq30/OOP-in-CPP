#include <iostream>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    void setLength(double len) {
        length = len;
    }

    void setWidth(double wid) {
        width = wid;
    }

    double getArea() const {
        return length * width;
    }
};

int main() {
    Rectangle rect;
    double length, width;

    cout << "Enter the length of the rectangle: ";
    cin >> length;
    rect.setLength(length);

    cout << "Enter the width of the rectangle: ";
    cin >> width;
    rect.setWidth(width);

    cout << "The area of the rectangle is: " << rect.getArea() << endl;

    return 0;
}
