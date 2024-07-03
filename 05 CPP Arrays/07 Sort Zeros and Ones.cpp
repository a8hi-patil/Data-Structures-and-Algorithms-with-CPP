#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void printArray( int arr[], int size){
    for( int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void countZerosAndOnesThenFillMethod( int arr[], int size){
    int countOfZero = 0;
    int countOfOne = 0;
    for( int i = 0 ; i < size ; i++){
        if( arr[i] == 0){
            countOfZero++;
        }else{
            countOfOne++;
        }
    }
    fill(arr,arr+countOfZero,0);
    fill(arr+countOfZero,arr+countOfZero+countOfOne,1);
}
void sortArrayUsingInBuiltSortFunction( int arr[],int size){
    sort(arr,arr+size);
}
void usingTwoPointerMethod(int arr[],int size){
    int start = 0;
    int end = size - 1;
    while( start < end ){
        if(arr[start] == 0){
            start++;
        }else if( arr[end] == 1){
            end--;
        }else{
            swap(arr[start],arr[end]);
        }
    }
}
int main()
{
    int arr[5]={1,0,0,0,1};
    int size =5;
    countZerosAndOnesThenFillMethod(arr,size);
    printArray(arr,size);
    int arrTwo[5]={1,0,1,0,1};
    sortArrayUsingInBuiltSortFunction(arrTwo,size);
    printArray(arrTwo,size);
    int arrThree[5]={1,0,1,1,1};
    usingTwoPointerMethod(arrThree,size);
    printArray(arrThree,size);
    return 0;
}