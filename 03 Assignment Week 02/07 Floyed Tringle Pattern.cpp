#include<iostream>
using namespace std;

int main ( ){
    int n;
    int val = 1;
    cout<<"Enter number of rows : ";
    cin >> n;
    for (size_t row = 0; row < n; row++)
    {
       for (size_t col = 0; col < row+1; col++)
       {
        cout<<val++<<" ";
       }
       cout<<endl;
    }
    
    return 0;
}