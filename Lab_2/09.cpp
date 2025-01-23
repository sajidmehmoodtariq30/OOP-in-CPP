#include <iostream>
#include <string>

using namespace std;

class Config {
private:
    string key;
    string value;

public:
    Config(const string& k) {
        key = k;
    }

    string getKey() const {
        return key;
    }

    void setValue(const string& v) {
        value = v;
    }
};

int main() {
    Config config("myKey");

    cout << "Key: " << config.getKey() << endl;

    config.setValue("myValue");

    return 0;
}