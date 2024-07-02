#include<iostream>
using namespace std;

int main ( ) {

    cout << "Enter number of rows : ";
    int rows;
    cin >> rows;
    for( int row = 0 ; row < 2*rows -1 ; row++){
        int cond = row < rows ? row : rows - ( row % rows) -2 ;
        for( int j = 0 ; j <= cond ; j++){
           cout<<"*" ;
        }
        cout << endl;
    }
    return 0;
}