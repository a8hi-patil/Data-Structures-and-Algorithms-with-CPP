#include<iostream>
using namespace std;

bool isNumberPrime( int num ){
    bool numIsPrime = true;
    for( int i = 2 ; i < num ; i++){
        if( num % i ==0){
            numIsPrime = false;
            break;
        }
    }
    return numIsPrime;
}
void print1ToNPrimeNumbers( int num ){
    for( int i = 2 ; i <= num ; i++){
        if( isNumberPrime( i )){
            cout<<i<<" ";
        }
    }
}
int main ( ){
    int n;
    cout<<"Enter number : ";
    cin >> n;
    print1ToNPrimeNumbers(n);
    return 0;
}