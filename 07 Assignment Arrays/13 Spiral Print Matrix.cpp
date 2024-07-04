#include<iostream>
#include<vector>
using namespace std;
void spiralPrintMatrix( vector<vector<int>> arr){
    int m = arr.size();
    int n = arr[0].size();
    int totalCount = m * n;
    int count = 0;
    int startingRow = 0;
    int endingCol = n -1;
    int endingRow = m -1;
    int startingCol = 0;

    while( count < totalCount){
        // row top
        for( int i = startingCol ; i <= endingCol ; i++){
            cout<<arr[startingRow][i]<<" ";
            count++;
        }
        startingRow++;
        // col end
        for( int i = startingRow ; i <= endingRow ; i++ ){
             cout<<arr[i][endingCol]<<" ";
            count++;
        }
        endingCol--;
        // row botton
         for( int i = endingCol ; i >= startingCol ; i-- ){
             cout<<arr[endingRow][i]<<" ";
            count++;
        }
        endingRow--;
        // col start 
         for( int i = endingRow ; i >= startingRow ; i-- ){
             cout<<arr[i][startingCol]<<" ";
            count++;
        }
        startingCol++;
    }
}
int main()
{
    vector<vector<int>> arr={{1,2,3},
                             {4,5,6},
                             {7,8,9}};
                             spiralPrintMatrix(arr);
    return 0;
}