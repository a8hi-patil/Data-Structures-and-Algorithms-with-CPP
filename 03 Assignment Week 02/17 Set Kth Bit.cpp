#include<iostream>
using namespace std;

int setKthBit( int num , int k){
    int mask = 1 << k;
    cout<<mask<<endl;
    int ans = num | mask;
    return ans;
}

int main ( ){
    int n,k;
    cout<<"Enter number : ";
    cin >> n;
    cout<<"Enter n'th bit : ";
    cin >> k;
    int res = setKthBit(n,k);
    cout<<"The number "<<n<<" becomes "<<res<<" after setting the "<<k<<" bit";
    return 0;
}