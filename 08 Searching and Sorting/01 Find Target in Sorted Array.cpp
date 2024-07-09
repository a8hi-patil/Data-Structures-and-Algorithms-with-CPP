#include<iostream>
using namespace std;

int binarySearch( int arr[], int size, int target){
    int start = 0;
    int end = size - 1;
    int mid = start + ( end - start)/2;
    while( start <= end ){
        if( arr[mid] == target){
            return mid;
        }else if( arr[mid] > target ){
            end = mid - 1;
        }else if( arr[mid] < target  ){
            start = mid + 1;
        }
        mid = start + ( end - start)/2;
        //Updatation is important.
        //Most people forgot to update the mid.
    }
    return -1;
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int size = 5;
    int target = 4;
    int targetIdx = binarySearch( arr,size,target);
    if( targetIdx == -1){
        cout<<"Target not found !!"<<endl;
    }else{
        cout<<"Target found at index "<<targetIdx<<" !!"<<endl;
    }
    int target1 = 24;
    int targetIdx1 = binarySearch( arr,size,target1);
    if( targetIdx1 == -1){
        cout<<"Target not found !!"<<endl;
    }else{
        cout<<"Target found at index "<<targetIdx1<<" !!"<<endl;
    }
    return 0;
}