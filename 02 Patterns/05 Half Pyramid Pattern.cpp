#include<iostream>
using namespace std;

int main ( ){
    int size;
    cout << "Enter size of the pyramid : ";
    cin >> size;
    
    for( int row = 0; row < size ; row++){
        for( int col = 0 ; col < row +1; col++ ){
            cout << "*";
        }
        cout<<endl;
    }
    return 0;
}