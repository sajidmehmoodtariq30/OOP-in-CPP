#include <iostream>

using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;

    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify()
    {
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
    }

public:
    Rational(int i = 0, int j = 1) : numerator(i), denominator(j)
    {
        while (denominator == 0)
        {
            cout << "Denominator cannot be zero: ";
            cin >> denominator;
        };
    }

    int getNumerator() const
    {
        return numerator;
    }

    int getDenominator() const
    {
        return denominator;
    }

    Rational operator+(const Rational &R) const
    {
        int commonDenominator = this->denominator * R.denominator;
        int newNumerator = this->numerator * R.denominator + R.numerator * this->denominator;
        Rational result(newNumerator, commonDenominator);
        result.simplify();
        return result;
    }

    Rational operator-(const Rational &R) const
    {
        int commonDenominator = this->denominator * R.denominator;
        int newNumerator = this->numerator * R.denominator - R.numerator * this->denominator;
        Rational result(newNumerator, commonDenominator);
        result.simplify();
        return result;
    }
    Rational operator*(const Rational &R) const
    {
        int commonDenominator = this->denominator * R.denominator;
        int newNumerator = this->numerator * R.numerator;
        Rational result(newNumerator, commonDenominator);
        result.simplify();
        return result;
    }
    Rational operator/(const Rational &R) const
    {
        int newNumerator = this->numerator * R.denominator;
        int commonDenominator = this->denominator * R.numerator;
        Rational result(newNumerator, commonDenominator);
        result.simplify();
        return result;
    }
};

void addRationals(const Rational &R1, const Rational &R2)
{
    Rational R3 = R1 + R2;
    cout << "Addition: " << R3.getNumerator() << "/" << R3.getDenominator() << endl;
}

void subtractRationals(const Rational &R1, const Rational &R2)
{
    Rational R3 = R1 - R2;
    cout << "Subtraction: " << R3.getNumerator() << "/" << R3.getDenominator() << endl;
}

void multiplyRationals(const Rational &R1, const Rational &R2)
{
    Rational R3 = R1 * R2;
    cout << "Multiplication: " << R3.getNumerator() << "/" << R3.getDenominator() << endl;
}

void divideRationals(const Rational &R1, const Rational &R2)
{
    Rational R3 = R1 / R2;
    cout << "Division: " << R3.getNumerator() << "/" << R3.getDenominator() << endl;
}



int main()
{
    Rational R1(3, 4);
    Rational R2(0, 6);

    int choice;
    do
    {
        cout << "Rational Menu:\n";
        cout << "1. Add Rationals\n";
        cout << "2. Subtract Rationals\n";
        cout << "3. Multiply Rationals\n";
        cout << "4. Divide Rationals\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addRationals(R1, R2);
            break;
        case 2:
            subtractRationals(R1, R2);
            break;
        case 3:
            multiplyRationals(R1, R2);
            break;
        case 4:
            divideRationals(R1, R2);
            break;
        case 5:
            cout << "Exiting Rational Menu...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
