#include<iostream>
#include <cstdlib>
using namespace std;
int calculatePowerOfTwo( int m,int n ){
    if( n == 1 ){
        return m;
    }
    return m * calculatePowerOfTwo( m,n -1 );
}
int main()
{
    system("cls");
    int n = 3;
    int m = 3;
    cout<<"The "<<n<<"th power of "<<m<<" is "<<calculatePowerOfTwo( m,n)<<" !"<<endl;
    return 0;
}