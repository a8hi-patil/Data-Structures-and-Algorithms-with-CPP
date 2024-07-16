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

    // Non Paramenterized Contructor
    Account()
    {
        cout << "Hi I am constructor " << endl;
        balance = 0;
        password = "abc@123";
    }
    // Paramterized Contructor
    Account(string accoundId, string username, int balance, string password)
    {
        cout << "Hi I am parameterized constructor  " << endl;
        this->accoundId = accoundId;
        this->balance = balance;
        this->password = password;
        this->username = username;
    }
    // Copy Contructor
    Account(Account &srcObj)
    {
        cout << "Hi I am Copy constructor  " << endl;
        this->accoundId = srcObj.accoundId;
        this->balance = srcObj.balance;
        this->password = srcObj.password;
        this->username = srcObj.username;
    }

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
    Account myAcc2("123", "Abhi", 800, "abh");
    myAcc2.getInfo();
    Account myAcc3(myAcc); // Invoking default copy constructor
    return 0;
}