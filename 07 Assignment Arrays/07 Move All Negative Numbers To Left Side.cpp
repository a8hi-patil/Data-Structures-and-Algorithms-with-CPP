#include<iostream>
#include<vector>
using namespace std;
void printArray( vector<int> arr){
    for(int i = 0 ; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}
void moveNegativeNumberToLeft( vector<int> &arr){
    int i = 0;
    int j = 1;
    while( j < arr.size()){
        if( arr[j] < 0){
            swap( arr[i],arr[j]);
            i++;
            j++;
        }else{
            j++;
        }
    }
}
int main()
{
    vector<int> arr={1,2,-3,4,-5,6,-7,8,9};
    moveNegativeNumberToLeft(arr);
    printArray(arr);
    return 0;
}