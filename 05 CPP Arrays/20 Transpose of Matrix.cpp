#include<iostream>
#include<vector>
using namespace std;
void print2DArray( vector<vector<int>> arr)
    {
        int row = arr.size();
        int col = arr[0].size();
        for( int i = 0 ; i < row ; i++){
            for( int j = 0 ; j < col ; j++){
                cout<<arr[i][j]<<" ,";
            }
            cout<<endl;
        }
    }

void transposeOfMatrix( vector< vector<int>> &arr){
     int row = arr.size();
        int col = arr[0].size();
        for( int i = 0 ; i < row ; i++){
            for( int j = i+1; j< col ; j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
}
int main()
{
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    print2DArray(arr);
    transposeOfMatrix(arr);
    print2DArray(arr);
    return 0;
}