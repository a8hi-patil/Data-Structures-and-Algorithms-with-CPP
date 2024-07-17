#include <iostream>
#include <cstdlib>
using namespace std;
void fun()
{
    int x = 0;
    cout << "Int x : " << x << endl;
    x++;
}
void fun2()
{
    static int y = 0;
    cout << "Int y : " << y << endl;
    y++;
}

class A
{
public:
    A()
    {
        cout << "Constructor" << endl;
    }
    ~A()
    {
        cout << "Destructor" << endl;
    }
};
int main()
{
    system("cls");
    fun();
    fun();
    fun();
    fun2();
    fun2();
    fun2();
    if (true)
    {
        A a;
    }
    cout << "endl if" << endl;

    if (true)
    {
        static A v;
    }
    cout << "end 2nd if" << endl;
    cout << "end main" << endl;
    return 0;
}