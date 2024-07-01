#include<iostream>
using namespace std;
int main (){
    cout << "Enter number of rows : ";
    int rows;
    cin >> rows;

    for( int row = 0; row<rows; row++ ){
        for( int col = 0 ; col<rows ; col++)
        cout << "*";
        cout << endl;
    }
    return 0;
}