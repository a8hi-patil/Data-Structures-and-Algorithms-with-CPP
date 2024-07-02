#include<iostream>
using namespace std;

int main ( ) {
    int rows;
    cout << "Enter number of rows : ";
    cin >> rows;

    for( int row = 0; row < rows; row++){
        for( int col = 0 ; col < rows - row ; col++){
            cout<<"*";
        }
        for( int col = 0 ; col <2*row +1 ; col++){
            cout<<" ";
        }
        for( int col = 0 ; col <rows - row  ; col++){
            cout<<"*";
        }
        cout<<endl;
    }

for( int row = 0; row < rows; row++){
        for( int col = 0 ; col < row+1 ; col++){
            cout<<"*";
        }
        for( int col = 0 ; col <2*rows -2*row-1 ; col++){
            cout<<" ";
        }
        for( int col = 0 ; col < row+1 ; col++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}