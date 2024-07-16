#include <iostream>
#include <cstdlib>
using namespace std;
// Parent class
class Parent
{
public:
    int id_p;

    void printId_p()
    {
        cout << "Parent ID is " << this->id_p << endl;
    }
};
// Sub-child-derrived class

class Child : public Parent
{
public:
    int id_c;
    void printId_c()
    {
        cout << "Child ID is " << this->id_c << endl;
    }
};
int main()
{
    system("cls");
    Child c;
    c.id_p = 7;
    c.printId_p();
    c.id_c = 9;
    c.printId_c();
    return 0;
}