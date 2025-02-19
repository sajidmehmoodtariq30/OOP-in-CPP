#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    void setValues(double r, double i) {
        real = r;
        imag = i;
    }

    Complex add(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    Complex subtract(Complex c) {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    Complex multiply(Complex c) {
        Complex temp;
        temp.real = real * c.real - imag * c.imag;
        temp.imag = real * c.imag + imag * c.real;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1, c2, result;
    c1.setValues(3, 4);
    c2.setValues(1, 2);

    result = c1.add(c2);
    cout << "Addition: ";
    result.display();

    result = c1.subtract(c2);
    cout << "Subtraction: ";
    result.display();

    result = c1.multiply(c2);
    cout << "Multiplication: ";
    result.display();

    return 0;
}
