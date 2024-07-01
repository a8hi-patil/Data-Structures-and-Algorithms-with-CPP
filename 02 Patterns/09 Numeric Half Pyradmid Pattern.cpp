#include<iostream>
using namespace std;
int main ( ){
    int rows ;
    cout << "Enter number of rows : ";
    cin >> rows;
    int counter = 1;
    for( int row = 0 ; row < rows ; row ++){
        for( int col = 0 ; col < row + 1 ; col++){
            cout << counter ;
            counter++;
        }
        cout<<endl;
    }
        return 0;
}