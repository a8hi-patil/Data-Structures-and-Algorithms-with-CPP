#include<iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    int a = 5;
    int *ptr = &a;
    cout<<a<<endl;
    cout<<&a<<endl;
    // cout<<*a<<endl;  // Gives error cause a is not pointer
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;
    // ptr = ptr + 1;
    cout<<ptr<<endl;
    cout<<*ptr/2<<endl;
    *ptr = *ptr + 1;
    cout<<*ptr<<endl;
    return 0;
}