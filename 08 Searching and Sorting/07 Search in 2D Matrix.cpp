#include<iostream>
#include<vector>

using namespace std;

bool findIn2DMatrix( vector<vector<int>> arr, int taget){
    int start = 0;
    int rows = arr.size();
    int cols = arr[0].size();
    int end = rows * cols;
    int mid = start + ( end - start)/2;

    while( start <= end){
        
        int rowIdx =  mid ==0 ? 0 : mid / cols;
        int colIdx = mid ==0 ? 0 : mid % cols;
        if( colIdx < cols && rowIdx < rows && arr[rowIdx][colIdx] == taget){
            return true;
        }else if( colIdx < cols && rowIdx < rows &&  arr[rowIdx][colIdx] < taget){
            start = mid +1;
        }else{
            end = mid -1;
        }
        mid = start + ( end - start)/2;

    }
    return false;
}

int main()
{
    vector<vector<int>> arr ={{1}};
    int target = 2;
    cout<<"Search in 2D array "<<endl;
    bool ans = findIn2DMatrix( arr,target);
    if( ans ){
        cout<<" FOUND "<<endl;
    }else{
        cout<<" NOT FOUND "<<endl;

    }
    return 0;
}