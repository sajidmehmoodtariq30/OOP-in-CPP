#include <iostream>
#include <string>

using namespace std;

class AccountDetail {
private:
    string name;
    int age;
    double balance;

public:
    // Constructor
    AccountDetail(string n, int a, double b) : name(n), age(a), balance(b) {}

    // Copy Constructor
    AccountDetail(const AccountDetail &other) : name(other.name), age(other.age), balance(other.balance) {}

    // Method to print account details
    void printDetails() const {
        cout << "Name: " << name << "\nAge: " << age << "\nBalance: " << balance << endl;
    }
};

int main() {
    // Create an AccountDetail object
    AccountDetail account1("John Doe", 30, 1500.50);

    // Use the copy constructor to create a new object
    AccountDetail account2 = account1;

    // Print details of the second object
    account2.printDetails();

    return 0;
}