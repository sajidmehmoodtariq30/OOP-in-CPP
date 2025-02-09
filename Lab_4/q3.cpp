#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;

public:
    // Constructor
    String(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Custom copy constructor (deep copy)
    String(const String& other, bool deepCopy) {
        if (deepCopy) {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        } else {
            str = other.str;
        }
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Function to display the string
    void display() const {
        cout << str << endl;
    }
};

int main() {
    String s1("Hello");
    String s2 (s1,false); // Shallow copy
    s1.display();
    s2.display();

    String s3(s1, true); // Deep copy
    s3.display();

    return 0;
}
