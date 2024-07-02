#include<iostream>
using namespace std;

int main(){
    int rows;
    cout << "Enter number of rows : ";
    cin >> rows;
    for( int row = 0 ; row < rows; row++){
        for( int col = 0 ; col < 2*row +1 ; col++){
            if(col & 1 == 1){
                cout << "*";
            }else{
                cout << row+1;
            }
        }
        cout<<endl;
    }
    return 0;
}