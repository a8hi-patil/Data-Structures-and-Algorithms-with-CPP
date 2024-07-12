#include<iostream>
#include <cstdlib>
using namespace std;
void printDigits( int n ){
    if( n == 0){
        return;
    }
    cout<<n%10<<" ";
    printDigits(n/10);
}
void printDigits2( int n ){
    if( n == 0){
        return;
    }
    printDigits2(n/10);
    cout<<n%10<<" ";
}

int main()
{
    system("cls");
    int n = 701213;
    printDigits(n);
    cout<<endl;
    printDigits2(n);
    return 0;
}