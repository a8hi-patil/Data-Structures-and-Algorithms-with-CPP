#include<iostream>
using namespace std;

int main(){

    int rows,cols;
    cout << "Enter Number of rows : ";
    cin >> rows;
    cout << "Enter number of columns : ";
    cin >> cols;

    for( int row = 0; row < rows; row++){
        for( int col = 0 ; col < cols; col++){
            cout << "*";
        }
        cout<<endl;
    }
    return 0;
}