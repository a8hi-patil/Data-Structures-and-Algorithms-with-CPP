#include<iostream>
using namespace std;

int main ( ){
    int n;
    cout<<"Enter number of rows : ";
    cin >> n;
    for( int row = 0; row < 2*n -1 ; row ++){
        int cond = row < n ? row : n + ( n - row - 1);
        int spaceCount = row < n ? 2 * ( n - row - 1) : row - cond - 1;

        for ( int col = 0 ; col < 2 * n ; col++){
            if( col <= cond ){
                cout << "*";
            }else if( spaceCount > 0){
                cout << " ";
                spaceCount--;
            }else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}