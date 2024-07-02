#include<iostream>
using namespace std;

int main (){
    int rows;
    cout << "Enter number of rows : ";
    cin >> rows;
    
    for( int row = 0 ; row < rows; row++){
        char c ='A' -1;
        for( int col = 0 ; col < row ; col++){
            cout<<++c;
        }
        while (c>'A')
        {
            cout<<--c;
        }
       cout<<endl; 
    }

    return 0;
}