#include<iostream>
using namespace std;

int main () {
    int rows;
    cout << "Enter the number of rows : ";
    cin >> rows;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col <  row; col++)
        {
            cout << " ";
        }
        for (int col = 0; col < rows - row; col++)
        {
            if( row == 0 || col == rows - row -1 || col==0){

            cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    

    return 0;
}