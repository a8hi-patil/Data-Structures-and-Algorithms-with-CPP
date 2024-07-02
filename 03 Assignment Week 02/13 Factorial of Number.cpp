#include<iostream>
using namespace std;

int findFactorialOfNumber( int num ){
    int factorial = 1;

    for( int i = 1; i <= num ; i++){
        factorial = factorial * i;
    }
    return factorial;
}

int main ( ){
    int n;
    cout<<"Enter number : ";
    cin >> n;
    int res = findFactorialOfNumber(n);
    cout<<"Factorial if number "<< n << " is "<< res;
    return 0;
}