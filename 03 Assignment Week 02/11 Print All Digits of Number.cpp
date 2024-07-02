#include<iostream>
using namespace std;

void printAllDigits( int num ){
    while (num)
    {
       cout<<num%10<<endl;
       num = num /10;
    }
    
}

int main ( ){
    int n;
    cout<<"Enter number : ";
    cin >> n;
    printAllDigits(n);
    return 0;
}