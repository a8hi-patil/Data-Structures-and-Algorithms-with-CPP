#include<iostream>
using namespace std;
void printArray( int arr[], int size){
    for( int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void rotateArrayByKPlaces(int arr[],int size, int k){
    // Calculating the final shift
    int finalShift = k%size;
    // If final shift is 0 no need to proceeding further
    if( finalShift == 0) return;
    // copying data in temporary array 
    int tempArray[1000];
    int index = 0;
    for( int i = size - finalShift ; i < size ; i++){
            tempArray[index] = arr[i];
            index++;
    }
    // shifting values in main array
    for( int i = size - finalShift ; i >= 0 ; i--){
        arr[i+finalShift] = arr[i];
    }
    //inserting data
    for( int i = 0 ; i < finalShift ; i++){
        arr[i]= tempArray[i];
    }
}

int main()
{
    int arr[5] = { 10,20,30,40,50};
    int size = 5;
    int shift = 2;
    printArray(arr,size);
    rotateArrayByKPlaces( arr,size,shift);
    printArray(arr,size);
    return 0;
}