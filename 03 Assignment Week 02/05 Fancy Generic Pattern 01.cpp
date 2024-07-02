#include<iostream>
using namespace std;

int main ( ){
    int n ;
    cout << "Enter number of rows : ";
    cin >> n;
    for ( int row = 0 ; row < n ; row++){
        int startIndex = 8 - row ;
        int count = row + 1;
        int num = count;
        for( int col = 0 ; col < 17 ; col++){
            if( col == startIndex && count > 0){
                cout<<num;
                startIndex+=2;
                count--;
            }else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}