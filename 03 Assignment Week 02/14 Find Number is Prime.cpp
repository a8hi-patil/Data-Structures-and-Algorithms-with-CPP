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

int main ( ){
    int n;
    cout<<"Enter number : ";
    cin >> n;
    int res = isNumberPrime(n);
    if(res){
        cout<<"Number "<<n<<" is Prime";        
    }else{
        cout<<"Number "<<n<<" is not Prime";        
    }
    return 0;
}