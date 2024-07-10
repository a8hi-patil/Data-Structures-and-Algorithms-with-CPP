#include<iostream>
using namespace std;
int findPeakIndexInMountainArrayLinearSearch( int arr[], int size){
    int maxIndex = -1;
    for( int i = 0 ; i < size ; i++){
        if( arr[i] > arr[i+1]){
            maxIndex = i;
            break;
        }
    }
    return maxIndex;
}
int findPeakIndexInMountainArrayBinarySearch( int arr[], int size){
    int start = 0;
    int end = size -1;
    int mid = start + (end - start )/2;
    cout<<mid;
    while( start != end){
        if( arr[mid] > arr[mid+1] ){
        // cout<<"A"<<endl;
                end = mid;
        }else{
        // cout<<"B"<<endl;
                start = mid+1;
        }
        mid = start + (end - start )/2;
    }
    return mid;
}
int main()
{
    int arr[7]={1,2,1,3,5,6,4};
    int size = 7;
    int peakIndex = findPeakIndexInMountainArrayLinearSearch(arr,size);
    cout<<"Peak Index is LS"<<peakIndex<<endl;
    int peakIndex1 = findPeakIndexInMountainArrayBinarySearch(arr,size);
    cout<<"Peak Index is BS "<<peakIndex1<<endl;
    return 0;
}