#include<iostream> 

using namespace std;

class PasswordManager {
private:
    string password;

public:
    void setPassword(const string& newPassword) {
        password = newPassword;
    }
};

int main(){
    PasswordManager pm;
    pm.setPassword("password");
   return 0;
}