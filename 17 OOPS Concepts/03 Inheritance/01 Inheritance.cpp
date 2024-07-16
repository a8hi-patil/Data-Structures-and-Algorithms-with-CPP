#include <iostream>
#include <cstdlib>
using namespace std;
class Base
{
public:
    int publicVar;
    void display()
    {
        cout << "Base public var is " << this->publicVar << endl;
    }
};

class Derrived : public Base
{
public:
    void displayMember()
    {
        display();
    }
    void modifyMember(int newVal)
    {
        publicVar = newVal;
    }
};
int main()
{
    system("cls");
    Derrived d;
    d.display();
    d.displayMember();
    d.modifyMember(39);
    d.display();
    d.displayMember();
    return 0;
}