#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void printMatrix( vector<vector <int>> matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    for( int i = 0 ; i < rows ; i++){
        for ( int j = 0 ; j < cols ; j++ ){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void transposeOfMatrix( vector<vector<int>> &matrix){
     int rows = matrix.size();
    int cols = matrix[0].size();
    for( int i = 0 ; i < rows -1 ; i++){
        for ( int j = i+1 ; j < cols ; j++ ){
            swap( matrix[i][j],matrix[j][i]);
        }
    }
}
void reverseRow( vector<vector<int>> &matrix ){
    int rows = matrix.size();
     for( int i = 0 ; i < rows  ; i++){
            reverse(matrix[i].begin(),matrix[i].end());
     }
}
int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    printMatrix(matrix);
    transposeOfMatrix(matrix);
    reverseRow(matrix);
    printMatrix(matrix);
    return 0;
}