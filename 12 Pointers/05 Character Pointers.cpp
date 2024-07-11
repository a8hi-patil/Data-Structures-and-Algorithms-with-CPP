#include<iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    char arr[20]="Abhijit";
    char *cptr = arr;
    cout<<cptr<<endl;
    cout<<*cptr<<endl;

    char a[10]="Patil";
    
    char *pt = a;

    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<a[0]<<endl;
    cout<<&a[0]<<"&a[0]"<<endl;
    cout<<pt<<endl;
    cout<<&pt<<endl;
    cout<<*pt<<endl;
    cout<<*(pt+3)<<endl;


    char ch[10]="Racecar";
    char *ptr = &ch[0];
    cout<<ch<<endl;
    cout<<&ch<<endl;
    cout<<ch[0]<<endl;
    cout<<&ch[0]<<"&ch[0]"<<endl;
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;
    cout<<*(ptr+3)<<endl;
    cout<<(ptr+3)<<endl;
    cout<<(ptr+2)<<endl;
    return 0;

}