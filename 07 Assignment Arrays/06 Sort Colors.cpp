#include<iostream>
#include<vector>
using namespace std;
void printArray( vector<int> arr){
    for(int i = 0 ; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}
void threePointer( vector<int> &arr){
    int low=0; int mid=0; int high= arr.size()-1;

    while( mid <= high){
        if( arr[mid] == 0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }else if( arr[mid] == 1){
            mid++;
        }else if( arr[mid] == 2){
            swap( arr[mid],arr[high]);
            high--;
        }
    }


}
int main()
{
    vector<int> arr={2,0,2,1,1,0};
    threePointer(arr);
    printArray(arr);
    return 0;
}