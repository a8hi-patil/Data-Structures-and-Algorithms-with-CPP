#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Account
{
private:
    double balance;
    string password;

    void setbalance(int amount, string transcation)
    {
        if (transcation == "CRED")
        {
            balance += amount;
        }
        else
        {
            balance -= amount;
        }
    }
    bool changePassword(string password)
    {
        if (this->password == password)
        {
            return false;
        }
        else
        {
            this->password = password;
            return true;
        }
    }

public:
    string accoundId;
    string username;

    void getInfo()
    {
        cout << "Account id is " << accoundId << " Acount name is " << username << endl;
    }
    void transaction(int amount, string type)
    {
        cout << "Trasaction is being procceded " << endl;
        int oldBalance = balance;
        setbalance(amount, type);
        cout << "Transaction completed" << endl;
        cout << "Old balance was " << oldBalance << " ! New balamce is " << balance << endl;
    }
};
int main()
{
    system("cls");
    Account myAcc;
    myAcc.username = "a8hi_patil";
    myAcc.accoundId = "01275176";
    myAcc.getInfo();
    myAcc.transaction(6000, "CRED");
    myAcc.transaction(16000, "CRED");
    myAcc.transaction(5000, "");
    return 0;
}