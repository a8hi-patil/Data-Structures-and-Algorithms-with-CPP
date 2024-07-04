#include<iostream>
using namespace std;

void rowWisePrinting( int arr[][3],int row, int col){
    for( int i = 0 ; i < row ; i++){
        for( int j = 0 ; j < col ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<",";
    }
}
void columnWisePrinting( int arr[][3],int row, int col){
    for( int i = 0 ; i < row ; i++){
        for( int j = 0 ; j < col ; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<",";
    }

}
void diagonalPrinting( int arr[][3],int row, int col){
    for( int i = 0 ; i < row ; i++){
            cout<<arr[i][i]<<" ";
        cout<<",";
    }

}
void reverseDiagonalPrinting( int arr[][3],int row, int col){
    for( int i = 0 ; i < row ; i++){
            cout<<arr[i][row - i -1]<<" ";
        cout<<",";
    }

}
int main()
{
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int row=3;
    int col=3;
    rowWisePrinting(arr,row,col);
    cout<<endl;
    columnWisePrinting(arr,row,col);
    cout<<endl;
    diagonalPrinting(arr,row,col);
    cout<<endl;
    reverseDiagonalPrinting(arr,row,col);
    return 0;
}