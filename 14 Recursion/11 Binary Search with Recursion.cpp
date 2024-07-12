#include<iostream>
#include <cstdlib>
using namespace std;
int binarySearch( int arr[], int size, int s , int e, int target){
    int mid = s + ( e - s)/2;
    while( s<=e){
        if( arr[mid] == target ){
            return mid;
        }else if( arr[mid] > target ){
            return binarySearch( arr,size,s,mid-1,target);
        }else{
            return binarySearch( arr,size,mid+1,e,target);
        }
        mid= s+(e-s)/2;
    }
    return -1;
}
int main()
{
    system("cls");
    int a[5] = {1,2,3,4,5};
    int size = 5;
    int target = 4;
    cout<<"Target "<<target<<" is found at index "<<binarySearch( a, size, 0 , size -1 , target);
    return 0;
}