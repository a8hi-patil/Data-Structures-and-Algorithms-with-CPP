#include<iostream>
using namespace std;

int findFirstOccurance( int arr[], int size,int target){
    int start = 0;
    int end = size -1;
    int mid = start + (end - start)/2;
    int firstOccuranceIdx = -1;
    while (start<=end)
    {
        if( arr[mid] == target){
            firstOccuranceIdx = mid;
            end = mid -1;
        }else if( arr[mid] > target){
            end = mid -1;
        }else{
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return firstOccuranceIdx;
    
}
int lastFirstOccurance( int arr[], int size,int target){
    int start = 0;
    int end = size -1;
    int mid = start + (end - start)/2;
    int lastOccuranceIdx = -1;
    while (start<=end)
    {
        if( arr[mid] == target){
            lastOccuranceIdx = mid;
            start = mid +1;
        }else if( arr[mid] > target){
            end = mid -1;
        }else{
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return lastOccuranceIdx;
    
}

int main()
{
    int arr[6]={5,7,7,8,8,10};
    int size = 6;
    int target = 8;
    cout<<"First occurance of target at index "<<findFirstOccurance(arr,size,target)<<endl;
    cout<<"Last occurance of target at index "<<lastFirstOccurance(arr,size,target)<<endl;
    return 0;
}