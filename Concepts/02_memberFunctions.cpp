#include <iostream>

using namespace std;

class Rectangle
{
private:
    int length;
    int width;
    // Other functions can also be written in the class
    int area()
    {
        return length * width;
    }

public:
    // Setter functions set the values of private members
    void setLength(int l)
    {
        if (l < 0)
            length = 0;
        else
            length = l;
    }
    void setWidth(int w);
    // Getter functions return the values of private members
    int getLength()
    {
        return length;
    }
    int getWidth()
    {
        return width;
    }
    void displayArea();
};

// Member functions can also be defined outside the class
void Rectangle::displayArea()
{
    cout << "Area: " << area() << endl;
}

void Rectangle::setWidth(int w)
{
    if (w < 0)
        width = 0;
    else
        width = w;
}

int main()
{
    Rectangle r1;
    r1.setLength(12);
    r1.setWidth(12);
    cout << r1.getLength() << endl;
    cout << r1.getWidth() << endl;
    r1.displayArea();
    return 0;
}