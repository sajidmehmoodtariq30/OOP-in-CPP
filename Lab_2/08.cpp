#include <iostream>

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int accountNumber, double initialBalance)
    {
        accountNumber = accountNumber;
        balance = initialBalance;
    }

    double getBalance() const
    {
        return balance;
    }

    void setBalance(double newBalance)
    {
        if (newBalance >= 0)
            balance = newBalance;
        else
            cout << "Error: Balance cannot be negative." << endl;
    }

    void deposit(double amount)
    {
        if (amount > 0)
            balance += amount;
        else
            cout << "Error: Deposit amount must be positive." << endl;
    }

    void withdraw(double amount)
    {
        if (amount > 0 && balance >= amount)
            balance -= amount;
        else
            cout << "Error: Insufficient funds or invalid withdrawal amount." << endl;
    }
};

int main()
{
    BankAccount account(123456, 1000.0);

    cout << "Initial Balance: $" << account.getBalance() << endl;

    account.deposit(500.0);
    cout << "Balance after deposit: $" << account.getBalance() << endl;

    account.withdraw(200.0);
    cout << "Balance after withdrawal: $" << account.getBalance() << endl;

    // account.setBalance(-100.0);

    return 0;
}