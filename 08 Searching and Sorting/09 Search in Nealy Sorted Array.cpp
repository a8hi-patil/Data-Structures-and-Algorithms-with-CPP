#include<iostream>
using namespace std;
int searchInSortedArray( int arr[], int size, int target){
        int start = 0;
        int end = size -1;
        int mid = start + ( end - start )/2;

        while( start <= end ){
            if( arr[mid] == target){
                return mid;
            }else if( mid+1 < size && arr[mid+1] == target ){
                return mid + 1;
            }else if( mid - 1 >= 0 && arr[mid-1] == target ){
                return mid - 1;
            }else if ( arr[mid] > target){
                end = mid - 2;
            }else{
                start = mid + 2;
            }
            mid = start + ( end - start )/2;
        }
        return -1;
};

int main()
{
    int arr[7]={10, 3, 40, 20, 50, 80, 70};
    int size = 5;
    int target = 40;
    int ans = searchInSortedArray( arr , size , target);
    if( ans == -1){
        cout<<"Target is not found in given nearly sorted array ):"<<endl;
    }else{
        cout<<"Target "<<target<<" fount in array at index "<<ans<<endl;
    }
    return 0;
}