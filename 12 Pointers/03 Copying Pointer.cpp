#include<iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    int a = 10;
    int *p = &a;
    int *q = p;

    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;
    cout<<q<<endl;
    cout<<&q<<endl;
    cout<<*q<<endl;
    return 0;
}