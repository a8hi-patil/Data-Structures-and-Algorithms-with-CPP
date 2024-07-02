#include<iostream>
using namespace std;
int main (){
    int rows;
    cout << "Enter the number of rows";
    cin >> rows;
    int k = rows;
    for( int row =0 ; row< rows; row++){
        int c = 1;
        for( int col = 0 ; col < k ; col++){
            if( col < rows - row -1){
                cout<<" ";
            }else if(col <= rows-1){
                cout<<c;
                c++;
            }else if( col == rows){
                c =  c -2;
                cout<< c;
                c--;
            }else{
                cout<<c;
                c--;
            }
        }
        k++;
        cout << endl;
    }
    return 0;
}