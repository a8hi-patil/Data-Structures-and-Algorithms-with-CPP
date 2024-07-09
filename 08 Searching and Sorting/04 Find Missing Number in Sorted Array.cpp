#include<iostream>
using namespace std;
int missingNumber( int arr[], int size){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start )/2;

    while(start <= end){
        if( arr[mid] == mid+1 ){
            start = mid+1;
        }else{
            end = mid -1;
        }
        // DO NOT FORGET TO UPDATE THE MID
        mid = start + (end - start )/2;

    }
    return mid;

}
int main()
{
    int arr[7]={1, 2, 3, 4, 6, 7, 8};
    int size = 7;
    int missingNumIdx = missingNumber( arr, size);
    cout<<"Missing number in array is "<<missingNumIdx+1<<endl;
    return 0;
}