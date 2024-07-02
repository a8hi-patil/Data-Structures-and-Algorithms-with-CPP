#include<iostream>
using namespace std;

int countActiveBits( int num ){
    int count = 0 ;
    while( num ){
        if( num & 1){
            count++;
        }
        num = num >> 1;
    }
    return count;
}

int main () {
    int n ;
    cout<<"Enter the number : ";
    cin >> n;
    int res = countActiveBits( n );
    cout<<"Active bits of number "<<n<<" are "<<res;
    return 0;
}