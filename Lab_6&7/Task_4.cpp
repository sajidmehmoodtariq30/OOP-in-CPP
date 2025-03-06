#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int breadth;

public:
    // Default constructor
    Rectangle() : length(0), breadth(0) {}

    // Parameterized constructor
    Rectangle(int l, int b) : length(l), breadth(b) {}

    // Setter functions
    void setLength(int l) { length = l; }
    void setBreadth(int b) { breadth = b; }

    // Getter functions
    int getLength() const { return length; }
    int getBreadth() const { return breadth; }

    // Function to sum two rectangles
    Rectangle Sum(const Rectangle& r) {
        return Rectangle(length + r.length, breadth + r.breadth);
    }

    // Function to display values
    void Display() const {
        cout << "Length: " << length << ", Breadth: " << breadth << endl;
    }
};

int main() {
    // Creating Rectangle objects
    Rectangle R1(5, 7), R2(2, 3), R3;

    cout << "\nValues of Rectangle 1: ";
    R1.Display();

    cout << "\nValues of Rectangle 2: ";
    R2.Display();

    // Summing R1 and R2 and storing result in R3
    R3 = R1.Sum(R2);  

    cout << "\nValues of Rectangle 3: ";
    R3.Display();

    return 0;
}
