#include<iostream>
#include <cstdlib>
using namespace std;
int sum( int n ){
    if( n == 1 ){
        return 1;
    }
    return n + sum( n -1);
}
int main()
{
    system("cls");
    int n ;
    cin>>n;
    cout<<"The sum of numbers 1 to "<<n<<" are = "<<sum(n)<<endl;
    return 0;
}