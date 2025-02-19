#include <iostream>
using namespace std;

class Book {
private:
    string title, author;
    double price;

public:
    void setBook(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
    }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    double getPrice() { return price; }

    Book applyDiscount(double percent) {
        price -= price * (percent / 100);
        return *this;
    }

    Book comparePrice(Book b) {
        return (price < b.price) ? *this : b;
    }
};

int main() {
    Book b1, b2;
    b1.setBook("Book A", "Author X", 500);
    b2.setBook("Book B", "Author Y", 450);

    Book cheaper = b1.comparePrice(b2);
    cout << "Cheaper Book: " << cheaper.getTitle() << endl;

    return 0;
}