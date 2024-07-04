#include<iostream>
#include<vector>
using namespace std;
int minimumValueIn2DArray( vector <vector<int>> arr){
    int row = arr.size();
    int col = arr[0].size();
    int minimumVal = INT_MAX;
    for( int i = 0; i <row ; i++){
        for( int j = 0 ; j< col; j++){
            if( arr[i][j] < minimumVal)
            minimumVal = arr[i][j];
        }
    }
    return minimumVal;
}
int main()
{
    vector<vector<int>> arr ={{1,2,3},{4,5,6},{7,8,9}};
    int row=3;
    int col=3;
    int minVal = minimumValueIn2DArray(arr);
    cout<<"Minimum value in 2D array is "<<minVal<<endl;
    return 0;
}