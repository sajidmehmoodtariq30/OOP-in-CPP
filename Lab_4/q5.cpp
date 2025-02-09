#include <iostream>
#include <string>

using namespace std;

class dayType {
private:
    string day;
    string daysOfWeek[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

public:
    // Constructor to initialize the day
    dayType(string d) {
        bool validDay = false;
        for (int i = 0; i < 7; ++i) {
            if (daysOfWeek[i] == d) {
                validDay = true;
                break;
            }
        }
        if (validDay) {
            day = d;
        } else {
            day = "Sun"; // Default to Sunday if invalid day is provided
        }
    }

    // Function to print the day
    void printDay() const {
        cout << "Day: " << day << endl;
    }

    // Function to return the day
    string getDay() const {
        return day;
    }

    // Function to return the next day
    string getNextDay() const {
        for (int i = 0; i < 7; ++i) {
            if (daysOfWeek[i] == day) {
                return daysOfWeek[(i + 1) % 7];
            }
        }
        return "Invalid day";
    }

    // Function to return the previous day
    string getPreviousDay() const {
        for (int i = 0; i < 7; ++i) {
            if (daysOfWeek[i] == day) {
                return daysOfWeek[(i + 6) % 7];
            }
        }
        return "Invalid day";
    }

    // Function to calculate and return the day by adding certain days to the current day
    string addDays(int numDays) const {
        for (int i = 0; i < 7; ++i) {
            if (daysOfWeek[i] == day) {
                return daysOfWeek[(i + numDays) % 7];
            }
        }
        return "Invalid day";
    }
};

int main() {
    dayType today("Tue");

    today.printDay();
    cout << "Next Day: " << today.getNextDay() << endl;
    cout << "Previous Day: " << today.getPreviousDay() << endl;
    cout << "Day after adding 4 days: " << today.addDays(4) << endl;
    cout << "Day after adding 13 days: " << today.addDays(13) << endl;

    return 0;
}
