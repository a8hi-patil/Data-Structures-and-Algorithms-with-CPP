#include<iostream>
using namespace std;
int main()
{   
    int a = 5;
    int b = 10;
    cout<<"values A :"<<a<<" And B :"<<b<<endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout<<"values A :"<<a<<" And B :"<<b<<endl;

    int c = 15;
    int d = 20;
    cout<<"values C :"<<c<<" And D :"<<d<<endl;
    c = c^d;
    d = c^d;
    c = c^d;
    cout<<"values C :"<<c<<" And D :"<<d<<endl;


    return 0;
}