#include<iostream>
using namespace std;

void checkOddOrEven( int num){
    if( num & 1){
        cout<<"Number "<<num<<" is Odd";
    }else{
        cout<<"Number "<<num<<" is Even";

    }
}
int main ( ){
    int n;
    cout<<"Enter number : ";
    cin >> n;
    checkOddOrEven( n );
    return 0;
}