#include<iostream>
using namespace std;

void printArray( int arr[],int size){

    for( int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int negativeMarking( int arr[] , int size){
    for( int i = 0 ; i < size ; i++){
        if( arr[i] < 0){
            continue;
        }else{
            arr[arr[i]]*=-1;
        }
    }
    for( int i = 1 ; i < size ; i++){
            if( arr[i] > 0){
                return i;
            }
    }
    return -1;
}
int main()
{
    int arr[5]={1,3,5,3,4};
    int size = 5;
    
    int missingNumber = negativeMarking(arr,size);
    cout<<"Missing number is "<<missingNumber<<endl;
   
    return 0;
}