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

class MyString {
    private:
        char *data;
        int size;
    
        int getLen(const char *str) {
            int len = 0;
            while (str[len] != '\0') len++;
            return len;
        }
    
        void copyStr(char *&dest, const char *src) {
            int len = getLen(src);
            dest = new char[len + 1];
            for (int i = 0; i < len; i++)
                dest[i] = src[i];
            dest[len] = '\0';
        }
    
    public:
        MyString() : data(new char[1]{'\0'}), size(0) {}
    
        MyString(const char *str) {
            size = getLen(str);
            copyStr(data, str);
        }
    
        MyString(const MyString &other) {
            size = other.size;
            copyStr(data, other.data);
        }
    
        MyString &operator=(const MyString &other) {
            if (this != &other) {
                delete[] data;
                size = other.size;
                copyStr(data, other.data);
            }
            return *this;
        }
    
        ~MyString() {
            delete[] data;
        }
    
        int getSize() const {
            return size;
        }
    
        MyString operator+() const {
            return *this;
        }
    
        MyString operator-() const {
            MyString result;
            int j = 0;
            result.data = new char[size + 1];
            for (int i = 0; i < size; i++) {
                if (data[i] != ' ')
                    result.data[j++] = data[i];
            }
            result.data[j] = '\0';
            result.size = j;
            return result;
        }
    
        MyString operator+(const MyString &str) {
            MyString result(*this);
            char *newData = new char[size + str.size + 1];
            int i = 0;
            for (; i < size; i++)
                newData[i] = data[i];
            for (int j = 0; j < str.size; j++, i++)
                newData[i] = str.data[j];
            newData[i] = '\0';
            delete[] result.data;
            result.data = newData;
            result.size = size + str.size;
            return result;
        }
    
        MyString operator-(const MyString &str) {
            MyString result(*this);
            int newSize = size;
            for (int i = 0; i < size - str.size + 1; i++) {
                bool found = true;
                for (int j = 0; j < str.size; j++) {
                    if (data[i + j] != str.data[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    for (int j = i; j < size - str.size; j++) {
                        result.data[j] = result.data[j + str.size];
                    }
                    newSize -= str.size;
                    i--;
                }
            }
            result.data[newSize] = '\0';
            result.size = newSize;
            return result;
        }
    
        MyString operator*(int times) {
            int newSize = size * times;
            char *newData = new char[newSize + 1];
            for (int i = 0; i < newSize; i++) {
                newData[i] = data[i % size];
            }
            newData[newSize] = '\0';
            return MyString(newData);
        }
    
        MyString &operator+=(const MyString &str) {
            *this = *this + str;
            return *this;
        }
    
        MyString &operator-=(const MyString &str) {
            *this = *this - str;
            return *this;
        }
    
        MyString &operator*=(int times) {
            *this = *this * times;
            return *this;
        }
    
        MyString &operator/=(char delimiter) {
            *this = (*this / delimiter)[0];
            return *this;
        }
    
        bool operator==(const MyString &other) const {
            if (size != other.size) return false;
            for (int i = 0; i < size; i++) {
                if (data[i] != other.data[i]) return false;
            }
            return true;
        }
    
        bool operator<(const MyString &other) const {
            int i = 0;
            while (data[i] != '\0' && other.data[i] != '\0') {
                if (data[i] < other.data[i]) return true;
                if (data[i] > other.data[i]) return false;
                i++;
            }
            return size < other.size;
        }
    
        MyString *operator/(char delimiter) {
            int count = 1;
            for (int i = 0; i < size; i++) {
                if (data[i] == delimiter) count++;
            }
    
            MyString *result = new MyString[count];
            int start = 0, index = 0;
            for (int i = 0; i <= size; i++) {
                if (data[i] == delimiter || data[i] == '\0') {
                    char *substr = new char[i - start + 1];
                    for (int j = start, k = 0; j < i; j++, k++)
                        substr[k] = data[j];
                    substr[i - start] = '\0';
                    result[index++] = MyString(substr);
                    delete[] substr;
                    start = i + 1;
                }
            }
            return result;
        }
    
        void display(MyString *arr, int count) {
            for (int i = 0; i < count; i++) {
                cout << "String: " << arr[i] << " (Size: " << arr[i].getSize() << ")" << endl;
            }
        }
    
        friend ostream &operator<<(ostream &os, const MyString &str) {
            os << str.data;
            return os;
        }
    
        friend istream &operator>>(istream &is, MyString &str) {
            char buffer[1000];
            is.getline(buffer, 1000);
            str = MyString(buffer);
            return is;
        }
    };

    
void rationalMenu()
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
}

void stringMenu()
{
    MyString s1("Hello");
    MyString s2(" World");

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    MyString s3 = s1 + s2;
    cout << "Concatenation (s1 + s2): " << s3 << endl;

    cout << "Equality (s1 == s2): " << (s1 == s2) << endl;
    cout << "Comparison (s1 < s2): " << (s1 < s2) << endl;

    MyString s4 = -s1;
    cout << "Removing spaces (-s1): " << s4 << endl;

    MyString s5 = s1 * 3;
    cout << "Repeating string (s1 * 3): " << s5 << endl;

    s1 += s2;
    cout << "After += operator (s1 += s2): " << s1 << endl;

    MyString *splitStrings = s3 / ' ';
    cout << "Split Strings: " << endl;

    int size = 0;
    for (; splitStrings[size].getSize() > 0; size++)
        ;
    ;

    s1.display(splitStrings, size);

    delete[] splitStrings;
}

int main()
{
    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. Rational Menu\n";
        cout << "2. String Menu\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            rationalMenu();
            break;
        case 2:
            stringMenu();
            break;
        case 3:
            cout << "Exiting Menu...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
    return 0;
}
