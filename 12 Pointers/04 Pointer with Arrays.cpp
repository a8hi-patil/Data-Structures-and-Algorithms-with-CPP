#include<iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    int arr[4]={10,20,30,40};
    int *ptr = arr;
    cout<<arr<<endl;
    cout<<&arr<<endl;
    cout<<arr[0]<<endl;
    cout<<&arr[0]<<endl;
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;
    cout<<*(ptr+2)<<endl;
    return 0;
}