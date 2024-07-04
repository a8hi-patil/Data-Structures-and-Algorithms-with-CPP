#include<iostream>
#include<vector>
using namespace std;
void printArray( vector<int> arr){
    for(int i = 0 ; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}
void usingPosMethod( vector<int> &arr){
    int ans = -1;
    for( int i = 0; i < arr.size();i++){
        int idx = abs(arr[i]);
        if( arr[idx] > 0){
            arr[idx]*=-1;
        }
    }
    for( int i = 0; i < arr.size() ; i++){
        if( arr[i] > 0){
            cout<<i<<" ";
        }
    }
}
int main()
{
    vector<int> arr={0,1, 3, 5, 3, 6};
    usingPosMethod(arr);
    // printArray(arr);
    return 0;
}