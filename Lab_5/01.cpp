#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double salary;

public:
    void setEmployee(string empName, double empSalary) {
        name = empName;
        salary = empSalary;
    }

    string getName() { return name; }
    double getSalary() { return salary; }

    void giveRaise(double percentage) {
        salary += salary * (percentage / 100);
    }

    Employee compareSalary(Employee e) {
        return (salary > e.salary) ? *this : e;
    }

    static double minWage() {
        return 15000.0; // Example minimum wage
    }
};

int main() {
    Employee e1, e2;
    e1.setEmployee("Alice", 50000);
    e2.setEmployee("Bob", 60000);

    Employee higherSalary = e1.compareSalary(e2);
    cout << "Employee with higher salary: " << higherSalary.getName() << endl;

    return 0;
}
