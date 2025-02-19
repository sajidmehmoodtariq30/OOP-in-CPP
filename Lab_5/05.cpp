#include <iostream>
using namespace std;

class Product {
private:
    string name;
    double price;
    int stock;

public:
    void setProduct(string n, double p, int s) {
        name = n;
        price = p;
        stock = s;
    }

    double getPrice() { return price; }
    int getStock() { return stock; }

    Product buy(int quantity) {
        if (quantity <= stock)
            stock -= quantity;
        else
            cout << "Insufficient stock!" << endl;
        return *this;
    }

    void applyDiscount(double percent) {
        price -= price * (percent / 100);
    }

    static double taxRate() {
        return 0.05;
    }
};

int main() {
    Product p;
    p.setProduct("Laptop", 1000, 10);

    p.applyDiscount(10);
    cout << "Price after discount: " << p.getPrice() << endl;

    p.buy(2);
    cout << "Stock after purchase: " << p.getStock() << endl;

    return 0;
}