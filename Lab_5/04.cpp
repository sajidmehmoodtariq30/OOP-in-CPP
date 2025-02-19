#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    int speed, fuel;

public:
    void setDetails(string b, int s, int f) {
        brand = b;
        speed = s;
        fuel = f;
    }

    Car& accelerate(int increase) {
        speed += increase;
        return *this;
    }

    Car& refuel(int amount) {
        fuel += amount;
        return *this;
    }

    void display() {
        cout << "Brand: " << brand << ", Speed: " << speed << ", Fuel: " << fuel << endl;
    }

    static int maxSpeed() {
        return 200;
    }
};

int main() {
    Car car1;
    car1.setDetails("Toyota", 50, 30);

    car1.accelerate(20).refuel(10);
    car1.display();

    return 0;
}