#include<iostream>
#include <cstdlib>
using namespace std;
void printArray( int arr[], int size,int idx){
    if(idx == size){
        return;
    }
    cout<<arr[idx]<<" ";
    printArray(arr,size,idx+1);

}
void printArray2( int arr[], int size,int idx){
    if(idx < 0){
        return;
    }
    cout<<arr[idx]<<" ";
    printArray2(arr,size,idx-1);

}
int main()
{
    system("cls");
    int a[5] = {1,2,3,4,5};
    int size = 5;
    printArray(a,size,0); 
    printArray2(a,size,size-1); 
    return 0;
}