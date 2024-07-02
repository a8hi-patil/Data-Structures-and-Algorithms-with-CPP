#include<iostream>
using namespace std;

int main ( ){
    int n;
    cout<<"Enter number of rows : ";
    cin >> n;
    for (int row = 0; row <= n; row++)
    {
        int c =1 ;
       for (int col =1; col < row+1; col++)
       {
        cout<<c<<" ";
        c= c*( row - col)/col;
       }
       cout<<endl;
    }
    
    return 0;
}