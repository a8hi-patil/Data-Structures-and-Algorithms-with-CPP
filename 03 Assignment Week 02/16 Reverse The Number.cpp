#include<iostream>
using namespace std;

int reverseNumber( int num ){
    int ans= 0;
    int rem = 0;
    bool isNegative = false;
    if( num <= INT_MIN){
        return 0;
    }
    if( num < 0 ){
        isNegative = true;
        num = -num;
    }
    while (num > 0)
    {
        if( ans > INT_MAX/10){
            return 0;
        }
        int digit = num % 10 ;
        ans = ans*10 + digit;
        num = num / 10;
    }
    return isNegative ? -ans : ans;
}

int main ( ){
    int n;
    cout<<"Enter number : ";
    cin >> n;
   int reversedNumber = reverseNumber( n );
   cout<< "Reverse of number "<<n<<" is "<<reversedNumber;
    return 0;
}