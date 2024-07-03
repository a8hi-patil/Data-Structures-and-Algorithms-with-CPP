#include<iostream>
using namespace std;

void printExtreams( int arr[],int size){

    int start = 0 ;
    int end = size -1;
    while( start < end){
        cout<<arr[start]<<" "<<arr[end]<<" ";
        start++;
        end--;
    }

}

int main()
{
    int arr[7]={10,20,30,40,50,60,70};
    int size = 7;
    printExtreams(arr,size);
    return 0;
}