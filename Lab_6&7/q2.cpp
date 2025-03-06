#include <string>
#include <iostream>

using namespace std;

class MyString
{
private:
    string s;

public:
    MyString() : s("") {}
    MyString(const string &str) : s(str) {}
    MyString(const char *str) : s(str) {}
    MyString(const MyString &other) : s(other.s) {}

    // Unary operators
    MyString operator+() const
    {
        return *this;
    }

    MyString operator-() const
    {
        MyString result;
        for (char c : s)
            if (c != ' ')
                result.s += c;

        return result;
    }

    // Binary operators
    MyString operator+(const MyString &other) const
    {
        return MyString(s + other.s);
    }

    MyString operator+(const char *other) const
    {
        return MyString(s + string(other));
    }

    MyString operator-(const MyString &other) const
    {
        MyString result(s);
        int pos = result.s.find(other.s);
        while (pos != -1)
        {
            result.s.erase(pos, other.s.length());
            pos = result.s.find(other.s);
        }
        return result;
    }

    MyString operator*(int n) const
    {
        MyString result;
        for (int i = 0; i < n; ++i)
            result.s += s;
        return result;
    }

    MyString* operator/(char delimiter) const
    {
        static MyString result[100];
        int index = 0;
        string temp;
        for (char c : s)
        {
            if (c != delimiter)
            {
                temp += c;
            }
            else
            {
                result[index++] = MyString(temp);
                temp.clear();
            }
        }
        if (!temp.empty())
        {
            result[index++] = MyString(temp);
        }
        return result;
    }

    // Compound assignment operators
    MyString &operator+=(const MyString &other)
    {
        s += other.s;
        return *this;
    }

    MyString &operator-=(const MyString &other)
    {
        int pos = s.find(other.s);
        while (pos != -1)
        {
            s.erase(pos, other.s.length());
            pos = s.find(other.s);
        }
        return *this;
    }

    MyString &operator*=(int n)
    {
        string temp = s;
        for (int i = 1; i < n; ++i)
        {
            s += temp;
        }
        return *this;
    }

    MyString &operator/=(char delimiter)
    {
        for (char &c : s)
        {
            if (c == delimiter)
            {
                c = ' ';
            }
        }
        return *this;
    }

    // Equality operators
    bool operator==(const MyString &other) const
    {
        return s == other.s;
    }

    bool operator!=(const MyString &other) const
    {
        return s != other.s;
    }

    // Comparison operators
    bool operator<(const MyString &other) const
    {
        return s < other.s;
    }

    bool operator<=(const MyString &other) const
    {
        return s <= other.s;
    }

    bool operator>(const MyString &other) const
    {
        return s > other.s;
    }

    bool operator>=(const MyString &other) const
    {
        return s >= other.s;
    }

    // Stream operators
    friend ostream &operator<<(ostream &os, const MyString &str)
    {
        os << str.s;
        return os;
    }

    friend istream &operator>>(istream &is, MyString &str)
    {
        is >> str.s;
        return is;
    }
};

int main()
{
    MyString s1("Sajid Mehmood Tariq");
    MyString s2("Mehmood");
    MyString s3("Tariq");
    MyString s4("Hello");
    MyString s5("World");

    // Unary operators
    cout << "+s1: " << +s1 << endl;
    cout << "-s1: " << -s1 << endl;

    // Binary operators
    cout << "s4 + s5: " << s4 + s5 << endl;
    cout << "s4 + \" Everyone\": " << s4 + " Everyone" << endl;
    cout << "s1 - s2: " << s1 - s2 << endl;
    cout << "s4 * 3: " << s4 * 3 << endl;

    // Division operator
    MyString* result = s1 / ' ';
    for (int i = 0; i < 100 && !result[i].operator==(MyString("")); ++i)
    {
        cout << "s1 / ' ' [" << i << "]: " << result[i] << endl;
    }

    // Compound assignment operators
    s4 += s5;
    cout << "s4 += s5: " << s4 << endl;

    s1 -= s2;
    cout << "s1 -= s2: " << s1 << endl;

    s4 *= 2;
    cout << "s4 *= 2: " << s4 << endl;

    s1 /= ' ';
    cout << "s1 /= ' ': " << s1 << endl;

    // Equality operators
    cout << "s4 == s5: " << (s4 == s5) << endl;
    cout << "s4 != s5: " << (s4 != s5) << endl;

    // Comparison operators
    cout << "s4 < s5: " << (s4 < s5) << endl;
    cout << "s4 <= s5: " << (s4 <= s5) << endl;
    cout << "s4 > s5: " << (s4 > s5) << endl;
    cout << "s4 >= s5: " << (s4 >= s5) << endl;

    // Stream operators
    MyString input;
    cout << "Enter a string: ";
    cin >> input;
    cout << "You entered: " << input << endl;

    return 0;
}
