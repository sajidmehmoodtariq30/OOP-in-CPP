#include <iostream>

using namespace std;

class Product
{
private:
    string name;
    double price;
    int stock;

public:
    double getPrice()
    {
        return price;
    }
    string getName()
    {
        return name;
    }
    int getStock()
    {
        return stock;
    }
    void setName(string newName)
    {
        name = newName;
    }
    void setPrice(double newPrice)
    {
        if (newPrice < 0)
        {
            cout << "Invalid Input Enter Price greater than 0: ";
            cin >> newPrice;
        }

        price = newPrice;
    }
    void setStock(int newStock)
    {
        if (newStock < 0)
        {
            cout << "Invalid Input Enter stock greater than 0: ";
            cin >> newStock;
        }
        stock = newStock;
    }
    void display()
    {
        cout << getPrice() << endl;
        cout << getName() << endl;
        cout << getStock() << endl;
    }
    void update()
    {
        string namme;
        double price;
        int stock;
        cout << "Enter new Name: ";
        cin >> name;
        setName(name);
        do
        {
            cout << "Enter new Price: ";
            cin >> price;
        } while (price < 1.00);
        setPrice(price);
        do
        {
            cout << "Enter new Stock: ";
            cin >> stock;
        } while (stock < 1);
        setStock(stock);
    }
};

int main()
{
    Product p1;
    p1.setName("Rehan");
    p1.setPrice(150);
    p1.display();
    p1.update();
    p1.display();
    return 0;
}