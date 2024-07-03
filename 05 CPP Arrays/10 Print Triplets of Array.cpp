#include<iostream>
using namespace std;
void printTriplets( int arr[], int size){
    for( int i = 0 ; i < size ; i++){
        for( int j = 0 ; j < size ; j++){
            for( int k = 0 ; k < size ; k++){
                cout<<"{"<<arr[i]<<","<<arr[j]<<","<<arr[k]<<"}, ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
void threeSum( int arr[], int size, int target){
    for( int i = 0 ; i < size ; i++){
        for( int j = 0 ; j < size ; j++){
            for( int k = 0 ; k < size ; k++){
                if(target == arr[i]+arr[j]+arr[k]){
                cout<<"{"<<arr[i]<<","<<arr[j]<<","<<arr[k]<<"} = "<<target<<endl;
                }
            }
        }
    }
}
int main()
{
    int arr[5] = { 10,20,30,40,50};
    int size = 5;
    int target = 120;
    printTriplets( arr,size);
    threeSum(arr,size,target);
    return 0;
}