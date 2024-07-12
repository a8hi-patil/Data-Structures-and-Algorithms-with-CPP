#include<iostream>
#include <cstdlib>
using namespace std;
int getFactorial( int n){
    if( n == 1 || n ==0 ){
        return 1;
    }
    return n * getFactorial(n-1);
}
int main()
{
    system("cls");
    int n = 5;
    cout<<"Factorial of "<<n<<" is "<<getFactorial( n )<<" !"<<endl;
    return 0;
}